#include "Print.h"
#include <memory>
#include <chrono>
#include<array>

class  Timer
{
public:
	 Timer() 
	 {
	     startTimePoint = std::chrono::high_resolution_clock::now();
	 }
	 ~Timer()
	 {
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
	 }

private:
	std::chrono::time_point<std::chrono::steady_clock> startTimePoint;
};

int MAIN27()
{
#pragma region FirsMeasureExample
	int value = 0;
	{
		Timer timer;
		for (int i = 0; i < 999999; i++)
			value += 2;
	}

	prt::Print(value);
#pragma endregion

#pragma region SeconMeasureExample
	struct Vector2
	{
		float x, y;
	};

#pragma region Ex1
	{
		prt::Print("Make shared");

		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;

		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}
#pragma endregion

#pragma region Ex2
	{
		prt::Print("New shared");

		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;

		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}
#pragma endregion

#pragma region Ex3
	{
		prt::Print("Make unique");

		std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;

		Timer timer;
		for (int i = 0; i < uniquePtrs.size(); i++)
			uniquePtrs[i] = std::make_unique<Vector2>();
	}
#pragma endregion

#pragma endregion

	return 0;
}