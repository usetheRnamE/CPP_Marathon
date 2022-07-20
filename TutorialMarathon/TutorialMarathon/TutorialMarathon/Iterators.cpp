#include <iostream>
#include <vector>

#include <unordered_map>

#include "Vector.h"

int MAIN42()
{
#pragma region GeneralInfo
#if 0

	std::vector<int> values = { 1, 4, 8, 8 };

#pragma region SimpIterator
	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << "\n";
#pragma endregion

#pragma region WithoutIVar
	for (int value : values)
		std::cout << value << "\n";
#pragma endregion

#pragma region ExtendedIterator

	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
		std::cout << *it << "\n";
#pragma endregion

#pragma region UsefulExample


	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map;

	//std::unordered_map<std::string, int> map;
	map["rosnia"] = 200;
	map["traktoris"] = 300;

	for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
	{
		auto& key = it->first;
		auto& value = it->second;

		std::cout << key << " = " << value << "\n";
	}

	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;

		std::cout << key << " = " << value << "\n";
	}

	for (auto [key, value] : map) //structure bindings
		std::cout << key << " = " << value << "\n";

#pragma endregion

#endif
#pragma endregion

#pragma region CustomIterator

	Vector<int> values;

	values.EmplaceBack(1);
	values.PushBack(4);
	values.EmplaceBack(8);
	values.PushBack(8);

	for (Vector<int>::Iterator it = values.begin(); it < values.end(); it++)
		std::cout << *it << std::endl;
#pragma endregion

	return 0;
}
