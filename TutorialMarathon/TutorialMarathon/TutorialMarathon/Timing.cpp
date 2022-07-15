#include <iostream>
#include <chrono>
#include <thread>

#define WAITANDRETURN std::cin.get();\
                      return 0;
#define END_LINE "\n"

#pragma region SmarterExample // smarter way to deal with chrono
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now(); //the timer starts when the object has been created
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now(); // thetimer ends when the object has been destroyed
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer duration: " << ms << "ms" << END_LINE; // here U also could test how much std::endl is slower than "\n"
	}

	void Function()
	{
		Timer timer; // obj created find more in ObjectLifetime.cpp

		for (int i = 0; i < 100; i++)
			std::cout << "Make some real and complicated shit" << END_LINE;
	} // obj destroyed
};
#pragma endregion

int MAIN17()
{
#pragma region SimpleExample // simple example how to deal with chrono

	auto start = std::chrono::high_resolution_clock::now(); //give us current time
	// find out more about auto in AutoKeyword.cpp file

	using namespace std::literals::chrono_literals; // find in Namespaces.cpp

	std::this_thread::sleep_for(1s); // find in Threads.cpp

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s" << END_LINE; //pretty close to an actual time
#pragma endregion

	WAITANDRETURN
}