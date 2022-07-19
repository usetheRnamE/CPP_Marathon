#include "Print.h"

#pragma region Example1

int GetValue()
{
	return 10; // 10 is R value
}

void EX1()
{
	int i = GetValue(); // "i" is L value
	int a = i;
}
#pragma endregion

#pragma region Example2
static void Print_russoNameLValue(const std::string& name) // L value
{
	prt::Print(name);
}
static void Print_russoNameRValue(std::string&& name) // R value
{
	prt::Print(name);
}

void EX2()
{
	std::string fName = "pituh";
	std::string sName = "ibaniy";

	std::string fullName = fName + sName;

	Print_russoNameLValue(fullName); //prints a L value 

	Print_russoNameLValue(fName + sName); //prints a R value (needs a const &)
	Print_russoNameRValue(fName + sName); //prints a R value (needs double & -> [&&])

}
#pragma endregion



int MAIN37()
{
	EX1();
	EX2();

	return 0;
}