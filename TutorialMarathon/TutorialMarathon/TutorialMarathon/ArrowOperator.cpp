#include <iostream>
#include <string>

#pragma region ForFirst2ExamplesUncomment
class Example3
{
private:
	int countOfDead_russianNazis;

public:
	Example3() :countOfDead_russianNazis(0) {}

#pragma region Getter/Setter //Encapsulation ebana rot
public:
	void SetNum(int numToSet)
	{
		countOfDead_russianNazis = numToSet;
	}
	int GetNum() const
	{
		return countOfDead_russianNazis;
	}
#pragma endregion

public:
	void Print() const { std::cout << "Fuck russo nazis" << "\n"; } //here we use const cuz this method doesnt change the class

};

class ScopedPtr2 //delete obj when it goes out of scope
{
private:
	Example3* myObj;

public:
	ScopedPtr2(Example3* example) : myObj(example) {}
	~ScopedPtr2() { delete myObj; }

public:
	Example3* operator->() //custom arrow operator
	{
		return myObj;
	}
	const Example3* operator->() const //custom arrow operator
	{
		return myObj;
	}
};
#pragma endregion //make sure u have uncommented this to use first 2 examples

struct Vector4
{
	float f, u, c, k;
};

int MAIN4() //rewrite to main in order to make this shit occur
{
//after u uncomment one method make sure you commented all another

#pragma region DefaultUsageOfAnArrowOperator
	/*Example ex;
	ex.Print();
	Example* exPtr = &ex;

	Example& exRef = *exPtr; //pretty shity, isnt it?
	exRef.Print(); //this is a bullshit too

	(*exPtr).Print(); //a bit better but looks like a complicated shit

	exPtr->Print(); //100% gigachad choice

	exPtr->SetNum(140000000);

	int gigaChadChoiceDead_russoNazisCount = exPtr->GetNum(); //This is a bad name for a variable. I just having fun

	std::cout <<"Dead russo nazis num: " + gigaChadChoiceDead_russoNazisCount << "\n"; // a bit messy but let it be*/
#pragma endregion

#pragma region CustomUsageOfAnArrowOperator

	/*ScopedPtr2 example = new Example3();
	const ScopedPtr2 constExample = new Example3();

	example->Print(); //here we use common arrow operator
	constExample->Print();//here we use const arrow operator

	example->SetNum(140000000);
    int gigaChadChoiceDead_russoNazisCount = example->GetNum();

	std::cout << "Dead russo nazis num: " + std::to_string(gigaChadChoiceDead_russoNazisCount) << "\n";*/
#pragma endregion

#pragma region CustomUsageOfAnArrowOperatorEx2

	int offset = (int) & ((Vector4*)nullptr)->f; //get offset of the value in the memory in bytes

	std::cout << offset << "\n";
#pragma endregion

	return 0;
	std::cin.get();
}