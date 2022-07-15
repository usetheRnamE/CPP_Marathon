#include <iostream>
#include <string>

#pragma region Example of a BAD code

void Print(int value)
{
	std::cout << value << "\n";
}

void Print(std::string value)
{
	std::cout << value << "\n";
}

void BADCodeFunc()
{
	Print(1488);
	Print("ruskie sosyt");
}
#pragma endregion

#pragma region TemplateUsageExampe1 //with functions
template <typename T>
//template <class T> // same as typename T 

void PrintF(T value) // don`t exist until we call it
{
	std::cout << value << "\n";
}
#pragma endregion

#pragma region TemplateUsageExampe2 //with classes
template<int N, typename K>

class NaziScum
{
private:
	const std::string homelandCountry = "russia";
	K bodyPartsCount[N];

public:
	float BodyPartsCount() const { return N; }
};
#pragma endregion

int MAIN8()
{
	//BADCodeFunc();

	PrintF(1488);
	PrintF("russo-shit sucks");

	PrintF<float>(14.88); //the same as before but with specified type

	NaziScum<2, std::string> russoPig;

	PrintF(russoPig.BodyPartsCount());

	return 0;
}