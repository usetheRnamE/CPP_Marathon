#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define END "\n"; //find in Macros.cpp

template <typename T> //find in Template.cpp
static void Print1(T value)
{
	std::cout << value << END;
}

int MAIN19()
{
	std::vector<int> values = { 1, 4, 8, 8 };

#pragma region Example1 //sorting values from a greater to lover
	std::sort(values.begin(), values.end(), std::greater<int>());


#pragma endregion

#pragma region Example2 // sorting values using lambdas (find more in Lambda.cpp)
	std::sort(values.begin(), values.end(), [](int a, int b) // if lambda returns true "a" would be first in a list and vice versa
	{
			if (a == 1)
				return false;
			else if (b == 1)
				return true;
			//in the example above we place 1 into the bottom of out list

			return a < b; //here u can play around with the statements
	});
#pragma endregion

	for (int value : values)
		Print1(value);

	return 0;

}