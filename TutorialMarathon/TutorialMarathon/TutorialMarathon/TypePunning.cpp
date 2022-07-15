#include <iostream>

#define END "\n"
//find in Macros.cp

template <typename T> //find in Template.cpp
static void Print2(T value)
{
	std::cout << value << END;
}

struct Object
{
	int x, y;
};

int MAIN20()
//type punning is actually about "converting" one variable memory adress to an another type 
{
#pragma region BetterAvoidExample
	int a = 50;
	double& convertedA = *(double*)&a; //here we acces int as it was a double (might cause a crush)

	Print2(convertedA);
#pragma endregion

#pragma region  RealLifeExample
	Object obj = { 5, 8 };

	int* position = (int*)&obj;

	//the code below is REALLY bad but good as an example
	int y = *(int*)((char*)&obj + 4); // get mem adress of the obj, conver it to char, plus 4 bites forward and conver all this to an int 

	Print2(position); //prints mem adress of the obj
	Print2(y); //prints Y variable of the obj
#pragma endregion

	return 0;
}