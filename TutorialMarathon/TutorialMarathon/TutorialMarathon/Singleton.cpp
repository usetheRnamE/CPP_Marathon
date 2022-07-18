#include "Print.h"

#pragma region Ex1
class Singleton
{
public:
	Singleton(const Singleton&) = delete; //delete the copy constuctor 

	static Singleton& Get()
	{
		return instance;
	}

	void Method()
	{
		prt::Print("Ass we can.");
	}

private:
	Singleton() {}

	static Singleton instance;
};

Singleton Singleton::instance;
#pragma endregion
namespace RandomNSP 
{
	static float randomNum = 14.88f;
	static float Float() { return randomNum; }
}
#pragma region ReverseEx1

#pragma endregion


#pragma region Ex2
class Random
{
public:
	Random(const Singleton&) = delete; //delete the copy constuctor 

	static Random& Get()
	{
		static Random instance;
		return instance;
	}

	static float Float() { return Get().FloatIm(); }

private:
	float FloatIm() { return 14.88f; }

	Random() {}
};


#pragma endregion

int main()
{

auto& instance = Singleton::Get();
	
instance.Method();

float num = Random::Float();
}
