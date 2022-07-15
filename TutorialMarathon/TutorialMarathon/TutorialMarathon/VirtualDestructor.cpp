#include <iostream>

#define END_LINE "\n";
//find in Macros.cpp

#define Border 	std::cout << "------------------------" << END_LINE

class NaziTank
{
public:
	NaziTank() { std::cout << "russo tank created" << END_LINE; }
	virtual ~NaziTank(){ std::cout << "russo tank destoyed" << END_LINE; }
};

class Nazies : public NaziTank
{
public:
	Nazies() { nazies = new int[5]; std::cout << "russo itself created" << END_LINE; }
	~Nazies() { delete[] nazies;  std::cout << "russo itself destoyed" << END_LINE; }

private:
	int* nazies;
};

int MAIN22()
{
	NaziTank* russoTank = new NaziTank();
	delete russoTank;

	Border

	Nazies* russo = new Nazies();
	delete russo;

	Border

	NaziTank* russoTankPoly = new Nazies(); // polymorphism usage
	delete russoTankPoly; // if NaziTank destructor isn`t marked as virtual we will call only NaziTank destructor othervise we called both Nazies and NaziTank destructor

	return 0;
}