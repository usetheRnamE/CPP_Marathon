#include <iostream>

void PrintSum(int a, int b)
{
	std::cout << a << "+" << b << " = " << (a + b) << std::endl;
}
int MAIN38()
{
	int value = 0;
	PrintSum(value++, value++); //we don`t know the order of executed code cuz it is undefined

	std::cin.get();
	return 0;
}