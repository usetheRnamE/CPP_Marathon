#include "Print.h"
#include <string>

class Bottle
{
public:
	virtual void RussoPenetration() //polymorphic type
	{

	}
};

class RussoNazi : public Bottle
{

};

class RussoMom : public Bottle
{

};

int MAIN24()
{
	Bottle* bottle = new RussoNazi(); // same as below
	RussoNazi* nazi = new RussoNazi(); // same as above

	Bottle* onBottleMom = new RussoMom();

	//RussoNazi* russo = new Bottle(); -> give us an error cuz bottle could has both type russo mom and russo itself
	RussoNazi* russo = (RussoNazi*)new Bottle(); // will cause a crush when we call some specific to a russoNazi  methods, but will work ok if both russoMom and russoNazi have this method 

	RussoNazi* russoDynamic = dynamic_cast<RussoNazi*>(new Bottle()); // requires polymotphic class
	if (russoDynamic)
	{
		prt::Print("Yeap russo pretty dynamically moves on the bottle");
	}

	//if cast valid dynamic cast returns ref else returns null

	return 0;
}