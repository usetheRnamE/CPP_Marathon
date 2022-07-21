#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;

	bool operator<(const CityRecord& other) const
	{
		return Population < other.Population;
	}
}

namespace std
{
	template <>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.name);
		}
	};
}

int main()
{
	std::vector<CityRecord> cities;

	cities.emplace_back("Lviv", 1000000);
	cities.emplace_back("Lytsk", 100000); // ahahhaha, voliniaki
	cities.emplace_back("Ternopil", 10000);
	cities.emplace_back("Drogobych", 2); //  1.5, actually

	for (const auto& city : cities)
		if (city.Name == "Drogobych") //string comperesion slow and bad
		{
			city.Population;
			break;
		}
	#pragma region MAP
	std::map<std::string, CityRecord> cityMap;

	cityMap["Lviv"] = CityRecord{ "Lviv" , 1000000 };
	cityMap["Lytsk"] = CityRecord{ "Lytsk" , 100000 };
	cityMap["Ternopil"] = CityRecord{ "Ternopil" , 10000 };
	cityMap["Drogobych"] = CityRecord{ "Drogobych" , 2 };
	#pragma endregion

	#pragma region UNORDERED_MAP
	std::unordered_map<CityRecord, uint32_t> foundedMap;

	foudedMap[CityRecord{ "Drogobych", 2 }] = 1488;

	foundedMap["Lviv"] = CityRecord{ "Lviv" , 1000000 };
	foundedMap["Lytsk"] = CityRecord{ "Lytsk" , 100000 };
	foundedMap["Ternopil"] = CityRecord{ "Ternopil" , 10000 };
	foundedMap["Drogobych"] = CityRecord{ "Drogobych" , 2 };

	CityRecord& lvivData = foundedMap["Lviv"];
	lvivData.Name = "The city of Gods";
	lvivData.Population;

	#pragma region CONST
	cityMap["Lviv"] = lvivData;

	std::unordered_map<CityRecord, uint32_t> constMap;
	const auto& cities = constMap;

	if (cities.find("Lviv") != cities.end())
		const CityRecord& lvivData = constMap.at("Lviv"); // for the const val we have to use .at
	#pragma endregion

	#pragma region ITERATION

	for (auto& [name, city] : foundedMap)
	{
		std::count << namee << " - " << city.Name << std::endl;
	}

	#pragma endregion

	cityMap.erase("Lytsk");

	#pragma endregion
}