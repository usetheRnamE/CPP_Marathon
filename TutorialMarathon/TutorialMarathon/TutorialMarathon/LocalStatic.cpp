#include<iostream>

int k; // won`t destroy when out a scope and can be called anywhere

class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance; 
	}

	void Upgrade_rUSSOPHOBIA() //bad naming but rUSSO must be written as the lowest case letter
	{
		printf("fuck this rUSSO_NAZI_PIGO_SCUM");
	}
};

void FunctionEX1()
{
	static int i = 0; // won`t destroy when out a scope and can be CALLED ONLY in this function
	i++;
	std::cout << i << "\n";
}

int MAIN6()
{
	Singleton::Get().Upgrade_rUSSOPHOBIA();

	std::cin.get();

	return 0;
}