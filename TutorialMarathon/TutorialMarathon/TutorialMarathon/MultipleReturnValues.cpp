#include <iostream>
#include <string>

#pragma region Example1 //use structure

class Leg
{
private:
	bool isLegEatenByTheDog;

	public:
		void Set(bool isEaten) { isLegEatenByTheDog = isEaten; }
		bool Get() { return isLegEatenByTheDog; }
};

struct Dead_rUSSO //bad naming but rUSSO must begin at lowercase
{
	Leg left, right;

	float distanceBTWLegs;
};

static Dead_rUSSO* GetLegsInfo() //here we are returning multiple values
{
	Dead_rUSSO* instance = new Dead_rUSSO();

	instance->left.Set(true);
	instance->right.Set(false);

	instance->distanceBTWLegs = 99.9;

	return instance;
}
#pragma endregion

#pragma region Example2 // play with refs

static void SumUping(int& dead_russoCount, int& satisfied_russoMotherCount, long double& avarage_russoPenisSize)
{
	dead_russoCount = 40000;
	satisfied_russoMotherCount = 40000;
		 
	avarage_russoPenisSize = .00001;
}
#pragma endregion

#pragma region Example3 //use tuple 
#include <tuple>

static std::tuple<float, int> Avarage_russoIndentify  (float iqLevel, int teethCount) 
{
	return std::make_pair(iqLevel, teethCount);
}


#pragma endregion


int MAIN7()
{
#pragma region Ex1 // Nice choice

	Dead_rUSSO* deady = GetLegsInfo();

	std::cout << "Distance between russo legs in km: " + std::to_string(deady->distanceBTWLegs) << "\n";

	std::string leftLegStatus = deady->left.Get() ? "Yes" : "No";
	std::string rightLegStatus = deady->right.Get() ? "Yes" : "No";

	std::cout << "is left russo leg eaten by a dog: " + leftLegStatus << "\n";
	std::cout << "is right russo leg eaten by a dog: " + rightLegStatus << "\n";

	delete deady;

#pragma endregion

#pragma region Ex2 //just OK
	int deadScum, satisfiedPigs;
	long double penisSize;

	SumUping(deadScum, satisfiedPigs, penisSize); //here we passed reference and change the value by it

	std::cout << "dead russo scum count: " + deadScum << "\n";
	std::cout << "satisfied russo mother-pigs count: " + satisfiedPigs << "\n";

	std::cout << "avarage russo penis size in nano meters: " + std::to_string(penisSize) << "\n";
#pragma endregion

#pragma region Ex3 //not very clean tho

	auto russoIndentify = Avarage_russoIndentify(-1, 0);


	std::cout << "russo`s IQ level: " + std::to_string(std::get<0>(russoIndentify))
		+ "\n russo`s teeth count: " + std::to_string(std::get<1>(russoIndentify)) << "\n";

#pragma endregion

	return 0;
}