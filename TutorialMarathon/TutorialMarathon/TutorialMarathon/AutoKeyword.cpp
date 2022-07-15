#include <iostream>
#include <vector>
#include <unordered_map>

#define WAIT std::cin.get(); // find in Macros.cpp

template <typename T> //find in Templates.cpp
void Print(T value) { std::cout << value << "\n"; }

static std::string GetCockName()
{
	return "shariy";
}

#pragma region AdditionToAutoUsageCase2

class Nazi{};

class NaziManager
{
private:
	std::unordered_map<std::string, std::vector<Nazi*>> CurrentNazi; // it `s really complicated to explain unordered map in comments so just look for: https://en.cppreference.com/w/cpp/container/unordered_map
public:
	const std::unordered_map<std::string, std::vector<Nazi*>>& GetNazies() const { return CurrentNazi; }
};

#pragma endregion


int MAIN11()
{
#pragma region GeneralExample //general explenation
	auto a = 288; //automaticaly define as int

	auto b = 14.88; //automaticaly define as float

	auto c = "Na slovah Ivan Bagriany, a na dili loh ybaniy"; //automaticaly define as string

	auto cockName = GetCockName(); // auto protects us from the type changing error 
	//if we change GetCockName type, this code will still work well

	//Auto causes code unclearness as well, thus we don`t understand what type is this variable, so better reduce usage of auto to minimum

	Print(a);
	Print(b);
	Print(c);
#pragma endregion

#pragma region CoolAutoUsageCase1 // aouto in usage
	std::vector<std::string> quotes;
	quotes.reserve(3); // get rid of copying process ( find in DynamicArraysAndOptimization.cpp )

	//Yeap, I`m too lazy to include cyrillic font
	quotes.emplace_back("Na slovah Ivan Franko, a na dili ybanko"); //На словах Іван Франко, а на ділі Їбанько
	quotes.emplace_back("Na slovah ty Pidmogylniy, a na dili her vanilny"); //На словах ти Підмогильний, а на ділі хер ванільний
	quotes.emplace_back("Promovlieyesh, iak Taras, a naspriavdi pidaras"); //Промовляєш, як Тарас, а насправді підарас

	for (auto it = quotes.begin(); /*here we write auto instead of -> std::vector<std::string>::iterator <- feel the difference*/
		it != quotes.end(); it++) //smth like foreach in C#, just go throught dynamic array
	{
		Print(*it);
	}
#pragma endregion

#pragma region CoolAutoUsageCase2 // auto in usage
	NaziManager nazimanager;

#pragma region ExampleOfBadCode // huge variable type just awful
	const std::unordered_map<std::string, std::vector<Nazi*>> nazies1 = nazimanager.GetNazies();
#pragma endregion

#pragma region WithoutAuto // how we can upgrade our code without auto
	using NaziesMap = std::unordered_map<std::string, std::vector<Nazi*>>; //here we just kinda "rename" this huge type
	// typedef std::unordered_map<std::string, std::vector<Nazi*>> NaziesMap //same shit as above

	const NaziesMap& nazies2 = nazimanager.GetNazies(); //and here we replace huge type by renamed one
#pragma endregion

#pragma region WithAuto // gigachad choice
	const auto& nazies3 = nazimanager.GetNazies(); // here have to use [&] anyway to show that it is a reference 
#pragma endregion

#pragma endregion


	/* To sum up, we commonly use auto keyword:
	 
	1) when we could get a type-change error (for instance because of changing function type)
	2) when our type is huge.
	3) when u don`t know what the type is gonna be in specific situation (for example u can use auto with templates)

	 In other cases better to avoid auto cuz it couse a code non-clearness
	*/

	WAIT

	return 0;
}