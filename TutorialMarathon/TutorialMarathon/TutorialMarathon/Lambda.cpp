#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define WAITANDRETURN std::cin.get(); \
                      return 0; // find in Macros.cpp

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) // here we use func pointer find more in a FunctionPointer.cpp file
{
	for (int value : values)
		func(value); //here we call a passed function
}

int MAIN14()
{
	std::vector<int> values = { 1, 4, 8 ,8 };

#pragma region PassValueToALabdas // Example of passing a value to the lambda
	int exampleVar1 = 1488;

	//mainly we use lambdas when we wanna specify the function but call it later
	auto lambdaVal = [=](int value) {std::cout << value << exampleVar1 << "\n"; }; // [=] -> means that we pass the value of the "var"
	auto lambdaRef = [&](int value) {std::cout << value << exampleVar1 << "\n"; }; // [&] -> means that we pass the reference of the "var"
	auto lambdaVar = [exampleVar1](int value) {std::cout << value << exampleVar1 << "\n"; }; // ["variable name"] -> means that we pass the variable itself
	
																							 
	ForEach(values, lambdaVal); // here we pass a lambda as a parameter 
	ForEach(values, lambdaRef); // here we pass a lambda as a parameter 
	ForEach(values, lambdaVar); // here we pass a lambda as a parameter //find more about auto in an AutoKeyword.cpp file
#pragma endregion

#pragma region ModifyValueInALambdas // Example of modifying value in the lambda
	int exambleVal2 = 228;

	auto lambdaMod = [=](int value) mutable {exambleVal2++; std::cout << value << exambleVal2 << "\n"; }; // to modify values that we passed in a lambdas we have to use "mutuable" keyword
	
	ForEach(values, lambdaMod); // here we pass a lambda as a parameter 
#pragma endregion

#pragma region LambdaUsageCase // Good pattern of lambda usage
	auto it = std::find_if(values.begin(), values.end(), [](int exampleValue) { return exampleValue > 3; }); // Here we iterate throught the dynamic array and find first value that is grater than 3

	std::cout << *it << "\n";
#pragma endregion

	WAITANDRETURN
}