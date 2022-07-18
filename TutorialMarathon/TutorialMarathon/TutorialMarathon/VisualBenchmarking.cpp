#include "Print.h"

#include <chrono>
#include <memory>
#include<array>
#include <fstream>

#pragma region JSONFileConstructing
struct ProfileResult
{
	std::string Name;
	long long Start, End;
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor
{
private:
	InstrumentationSession* currentSession;
	std::ofstream outputStream;
	int profileCount;
public:
	Instrumentor(): currentSession(nullptr), profileCount(0) {}

	void BeginSession(const std::string& name, const std::string& filepath = "results.json")
	{
		outputStream.open(filepath);

		WriteHeader();

		currentSession = new InstrumentationSession{name};
	}

	void EndSession()
	{
		WriteFooter();

		outputStream.close();

		delete currentSession;
		currentSession = nullptr;
		profileCount = 0;
	}

	void WriteProfile(const ProfileResult& result)
	{
		if (profileCount++ > 0)
			outputStream << ",";

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		outputStream << "{";
		outputStream << "\"cat\":\"function\",";
		outputStream << "\"dur\":" << (result.End - result.Start) << ',';
		outputStream << "\"name\":\"" << name << "\",";
		outputStream << "\"ph\":\"X\",";
		outputStream << "\"pid\":0,";
		outputStream << "\"tid\":0,";
		outputStream << "\"ts\":" << result.Start;
		outputStream << "}";

		outputStream.flush();
	}

	void WriteHeader()
	{
		outputStream << "{\"otherData\": {},\"tracEvents\":[";
		outputStream.flush();
	}

	void WriteFooter()
	{
		outputStream << "]}";
		outputStream.flush();
	}

	static Instrumentor& Get()
	{
		static Instrumentor* instance = new Instrumentor();
		return *instance;
	}
};
#pragma endregion

#pragma region Timer
class  InstrumentationalTimer
{
public:
	InstrumentationalTimer(const char* name) : timerName(name), isStopped(false)
	{
		startTimePoint = std::chrono::high_resolution_clock::now();
	}
	~InstrumentationalTimer()
	{
		if (!isStopped)
			StopTime();
	}

	void StopTime()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;

		double ms = duration * .001;

		prt::Print(duration);
		prt::Print(ms);

		Instrumentor::Get().WriteProfile({ timerName, start, end });

		isStopped = true;
	}

private:
	bool isStopped;
	std::string timerName;
	std::chrono::time_point<std::chrono::steady_clock> startTimePoint;
};
#pragma endregion

#pragma region Macros
#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationalTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
#define PROFILE_SCOPE(name)
#endif
#pragma endregion


static void Func1()
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
		prt::Print("Oh boiii");
}

static void Func2()
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
		prt::Print("Without further interruption, let's celebrate and suck some dick.");
	
}

int MAIN33()
{
	Instrumentor::Get().BeginSession("Profile");

	Func1();
	Func2();

	Instrumentor::Get().EndSession();

	return 0;
}
