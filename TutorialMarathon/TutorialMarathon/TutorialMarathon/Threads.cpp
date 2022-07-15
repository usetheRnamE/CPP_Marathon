#include <iostream>
#include <thread>

#define WAIT std::cin.get(); /* find in Marcos.cpp*/
#define END "\n"
static bool isFinished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals; //find in Namespaces.cpp

	std::cout << "Started thread ID: " << std::this_thread::get_id() << END; //getting ID o current thread

	while (!isFinished)
	{
		std::cout << "Working..." << END;
		std::this_thread::sleep_for(1s); //delays printing by 1 sec
	}
}

int MAIN16()
{
	std::thread worker(DoWork); // find in FunctionPointer.cpp

	WAIT
	isFinished = true; // another thread that can interupt worker thread

	worker.join(); // wait until worker thred is completed
	std::cout << "Finished..." << END;
	std::cout << "Started thread ID: " << std::this_thread::get_id() << END;

	WAIT
    return 0;
}