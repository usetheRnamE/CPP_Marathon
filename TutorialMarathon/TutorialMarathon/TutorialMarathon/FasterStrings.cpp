#include "Print.h"
#include <string>

static uint32_t s_AllocCount = 0;

void* operator new (size_t size)
{
	s_AllocCount++;


	return malloc(size);
}

static void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}

static void PrintName2(std::string_view name)
{
	std::cout << name << std::endl;
}

int MAIN33()
{
	std::string name = "ruskiy pidoras";

#pragma region  Ex1 // 8 allocationss
	PrintName(name);

	prt::Print(s_AllocCount);
#pragma endregion

#pragma region  Ex2 // 3 allocations
	std::string firstPart = name.substr(0, 6);
	std::string secondPart = name.substr(7, 12);
	PrintName(firstPart);

prt::Print(s_AllocCount);
#pragma endregion
	
#pragma region  Ex3 // 1 allocation
	std::string_view firstPart2(name.c_str(), 6);
	std::string_view secondPart2(name.c_str() + 6, 10);

	PrintName2(secondPart2);

	prt::Print(s_AllocCount);
#pragma endregion

#pragma region  Ex4 // 0 allocation
	const char* nameChar = "ruskiy pidoras";

	std::string_view firstPart3(nameChar, 6);
	std::string_view secondPart3(nameChar + 6, 10);

	PrintName2(secondPart3);

	prt::Print(s_AllocCount);
#pragma endregion

	std::cin.get();

	return 0;
}