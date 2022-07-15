#include<iostream>

namespace prt
{
	template<typename T>
	static void Print(T value)
	{
		std::cout << value << "\n";
	}
}