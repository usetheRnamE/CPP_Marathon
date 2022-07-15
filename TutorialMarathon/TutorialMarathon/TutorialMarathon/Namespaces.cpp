#include <iostream>
#include <algorithm>

//here we have 2 indentical functions but as they in a different namespaces they do not cause a conflict

namespace russoNaziScum
{
	bool isInUkraine;

	void PrintAverageLifetime()
	{
		float avarageLifetimeInSec = 0;

		if (isInUkraine)
			avarageLifetimeInSec = .0001;
		else
			avarageLifetimeInSec = 1555200000; // about 50 years

		std::cout << avarageLifetimeInSec << "\n";
	}
}

namespace UkrainianGigachad
{
	void PrintAverageLifetime()
	{
		std::cout << "Heroes never die" << "\n";
	}
}

namespace JustSomeExample
{
	void PrintAverageLifetime()
	{
		std::cout << "example" << "\n";
	}
}

namespace NestedNamespace 
{
namespace Functions
{
	void PrintAverageLifetime()
	{
		std::cout << "nested" << "\n";
	}
}
}

int MAIN15()
{
	using namespace russoNaziScum; // example of namespace usage
	PrintAverageLifetime();

	UkrainianGigachad::PrintAverageLifetime(); // example of namespace usage

	namespace ex = JustSomeExample; // example of namespace usage
	ex::PrintAverageLifetime();

	namespace nested = NestedNamespace::Functions; // example of nested namespace usage
	nested::PrintAverageLifetime();

	// !!! never declare namespaces in a header file and declare it in a smalles scopes possible

	return 0;
}