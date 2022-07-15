#include "Print.h"
#include <tuple>
#include <tuple>

#pragma region TupleUsage


#pragma endregion
std::tuple<std::string, int, bool> CreateCotton_T()
{
	return { "Bilgorod", 999, true };
}
#pragma region PairUsage
std::pair<std::string, int> CreateCotton_P() //only 2 parameters
{
	return { "Bilgorod", 999 };
}
#pragma endregion



int MAIN28()
{
#pragma region OldStyleUsage
	auto cotton_T = CreateCotton_T();
	auto cotton_P = CreateCotton_P();

	std::string& city = std::get<0>(cotton_T);
	int count = std::get<1>(cotton_T);
#pragma endregion

#pragma region StructureBindingsEx1 // too many lines of code
	std::string city2;
	int count2;
	bool isCottoned;

	std::tie(city2, count2, isCottoned) = CreateCotton_T();
#pragma endregion

#pragma region StructureBindingsEx2 //for a c++ 17 (and later)
	auto[city3, count3, isCottoned2] = CreateCotton_T();
#pragma endregion

	return 0;
}
