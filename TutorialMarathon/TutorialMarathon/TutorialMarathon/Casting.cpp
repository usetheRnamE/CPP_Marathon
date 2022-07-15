#include <iostream>
#include <string>

#define END_LINE "\n";
//find in Macros.cpp

#define Border 	std::cout << "------------------------" << END_LINE

#pragma region Classes
class NaziWarship
{
public:
	NaziWarship() { std::cout << "russo warship created" << END_LINE; }
	virtual ~NaziWarship() { std::cout << "russo warship destoyed" << END_LINE; }
};

class Nazies : public NaziWarship
{
public:
	Nazies() { nazies = new int[5]; std::cout << "russo itself created" << END_LINE; }
	~Nazies() { delete[] nazies;  std::cout << "russo itself destoyed" << END_LINE; }

private:
	int* nazies;
};

class NeptynMissle : public NaziWarship
{
	NeptynMissle() {}
	~NeptynMissle() {}
};
#pragma endregion

int MAIN23()
{
#pragma region CStyleCast
	double cValue = 5.25;
	double cVar = (int)cValue + 5.3; // C-style cast

	std::cout << "C-style cast res: " + std::to_string(cVar) << END_LINE;
#pragma endregion

#pragma region CPPStyleCast //make code more solid and better
#pragma region StaticCast
	double cppValue = 5.25;

	double cppVar = static_cast<int>(cppValue) + 5.3; //CPP-style cast

	std::cout << "CPP-style static cast res: " + std::to_string(cppVar) << END_LINE; //slower but has extra functionality + better syntax
#pragma endregion

#pragma region DynamicCast
	Nazies* russo = new Nazies();

	NaziWarship* russoWarship = russo;

	NeptynMissle* neptynMissle = dynamic_cast<NeptynMissle*>(russoWarship);
	if (neptynMissle)
		std::cout << "badabym" << END_LINE

#pragma endregion
#pragma endregion

	return 0;
}