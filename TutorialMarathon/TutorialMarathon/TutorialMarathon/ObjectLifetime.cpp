#include <iostream>
#include <string>

class Example2
{
public:
	Example2()
	{
	 printf("Example created");
	}

    ~Example2()
	{
	 printf("Example destroyed");
	}
};

int* CreateArray()
{
	 int array[50]; //WRONG (Will destroy while returning)

	 int* arrayCorrect = new int[50]; //Correct

	 return array;
}

class ScopedPtr1
{
private: 
	Example2* mPtr;

public:
	ScopedPtr1(Example2* ptr)
		: mPtr(ptr) {}
	~ScopedPtr1()
	{
		delete mPtr;
	}
};

int MAINONE() //rewrite to main to make this function work
{
#pragma region StackBased
	{
		Example2 ex; //obj created
	} //obg destroyed
#pragma endregion

#pragma region HeapBased
	{
		Example2* ex = new Example2(); //obj created
	} //obg DONT destroyed
#pragma endregion

	{
		ScopedPtr1 e(new Example2()); // obj created
	} //obj destroyed

	return 0;
	std::cin.get();
}
