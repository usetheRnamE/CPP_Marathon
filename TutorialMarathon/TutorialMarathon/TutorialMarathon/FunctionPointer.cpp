#include <iostream>
#include <vector>

#define WAITANDRETURN std::cin.get(); \
                      return 0; // find in Macros.cpp

template<typename T> // find in Template.cpp
static void Print(T value) // just a standart private function
{
	std::cout << value << "\n";
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value); //here we call a passed function
}

int MAIN13()
{

#pragma region ExampleOne // Main principes and explenation of a FuncPtr 
	Print("putin huilo"); // common function - common call

// find in AutoKeyword.cpp 
//auto exampleOne = PrintTheTruth; // get a function pointer (getting a memory adress of function) cuz function is basically a CPU instruction and we get mem location of this instruction
//use auto ONLY with parameterless functions

	void(*exampleTwo)(std::string) = Print; // same shit as above but without auto usage, in the second brackets we write a function`s parameter type if there is no parameter just leave it empty

	typedef void(*PrintTheTruthFunc)(std::string); // in the second brackets we write a function`s parameter type if there is no parameter just leave it empty
	PrintTheTruthFunc exampleThree = Print; // also does the same shit
	// !!! U can find more about typedef and auto in AutoKeword.cpp file

	//exampleOne(); //calling PrintTheTruth function;
	exampleTwo("rosnia - naciki"); // just same as above
	exampleThree("shariy pityh"); // just same as above
#pragma endregion

#pragma region ExampleTwo // Additional examples of FuncPtr usage
	std::vector<int> values = { 1, 4, 8 ,8 };

	ForEach(values, Print); // here we pass function as a parameter
	ForEach(values, [](int value) {std::cout << value << "\n"; }); // here we pass a lambda as a parameter ( get to know more about lambda in a Lambda.cpp file )
#pragma endregion

	WAITANDRETURN
}