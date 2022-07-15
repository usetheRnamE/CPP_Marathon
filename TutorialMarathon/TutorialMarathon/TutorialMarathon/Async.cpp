#include "Timer.h"
#include <future>

#pragma region Tasks
static void Task1()
{
	prt::Print("Task1");
}
static void Task2()
{
	prt::Print("Task2");
}
static void Task3()
{
	prt::Print("Task3");
}
static void Task4()
{
	prt::Print("Task4");
}
static void Task5()
{
	prt::Print("Task1");
}
static void Task6()
{
	prt::Print("Task2");
}
static void Task7()
{
	prt::Print("Task3");
}
static void Task8()
{
	prt::Print("Task4");
}
static void Task9()
{
	prt::Print("Task1");
}
static void Task10()
{
	prt::Print("Task2");
}
static void Task11()
{
	prt::Print("Task3");
}
static void Task12()
{
	prt::Print("Task4");
}
#pragma endregion

int MAIN30()
{
	auto tasks = { 
		Task1, Task2, Task3, Task4, Task5, Task6, 
		Task7, Task8,Task9,Task10,Task11,Task12 };

#define ASYNC 1

#if ASYNC
	{
		tmr::Timer timer;
		for (const auto& task : tasks)
			std::async(std::launch::async, task);
	}
#else
	{
		tmr::Timer timer;
		for (const auto& task : tasks)
			task();
    } 
#endif

	return 0;
}

