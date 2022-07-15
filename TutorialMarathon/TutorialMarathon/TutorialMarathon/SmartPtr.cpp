#include <iostream>
#include <string>

#pragma region ExampleClass
class Example1
{
public:
	Example1()
	{
		printf("Example created");
	}

	~Example1()
	{
		printf("Example destroyed");
	}

public:
	void ExampleMethod()
	{
		printf("hui bush?");
	}
};
#pragma endregion

int MAINTWO() //rewrite to main to make this function work
{
#pragma region UniquePrt //cannot be copied (cuz if 1 unique ptr destroyed all copies destroyed as well)
	{
		std::unique_ptr<Example1> exampleUNI(new Example1()); //No impleased convertion
		std::unique_ptr<Example1> saferExampleUNI = std::make_unique<Example1>(); //Somehow safer

		exampleUNI->ExampleMethod();
		saferExampleUNI->ExampleMethod();
	}
#pragma endregion

#pragma region SharedPtr // can be copied & increased ref count (keep ref alive)
	{
		std::shared_ptr<Example1> ex0; 
		{
			std::shared_ptr<Example1> exampleSHR = std::make_shared<Example1>(); //usse without <new> only (to prevent 2 allocations)

			ex0 = exampleSHR;
			exampleSHR->ExampleMethod();
		} // pointer dont destroyed cuz ex0 still alive

		//some usefull and really complicated code, for instance: printf("u`r sus");

	}//yup here all pointers died((
#pragma endregion
	
#pragma region WeakPtr //can be copied however dont increased ref count(NOT keep ref alive)
	{
		std::shared_ptr<Example1> ex0;
		{
			std::shared_ptr<Example1> exampleSHR = std::make_shared<Example1>(); //usse without <new> only (to prevent 2 allocations)
			std::weak_ptr<Example1> exampleWK = exampleSHR;

			ex0 = exampleSHR;
			exampleSHR->ExampleMethod();
		} // pointer dont destroyed cuz ex0 still alive

		//some usefull and really complicated code, for instance: printf("u`r sus");

	}//yup here all pointers died((
#pragma endregion

	return 0;
	std::cin.get();
}