#include "Print.h"
#include <variant>



std::variant<std::string> ReadFileAsString2()
{
	return{};
}

int MAIN31()
{
	std::variant<std::string, int> data; //provides us better optimization but less efficient than unions

	prt::Print(sizeof(data)); 
	prt::Print(sizeof(int));
	prt::Print(sizeof(std::string));


#pragma region  GeneralUsage


	data = "1488";
	prt::Print(data.index()); //returns 0
	prt::Print(std::get<std::string>(data));

	data = 1488;
	prt::Print(data.index()); //returns 1
	prt::Print(std::get<int>(data));
#pragma endregion

#pragma region GetIfMethod
	auto value = std::get_if<std::string>(&data); //returns pointer to a data


	if (value)
	{
		prt::Print(std::get<std::string>(data));
	}
	else
	{
		prt::Print(std::get<int>(data));
	}
#pragma endregion

	std::cin.get();

	return 0;
}