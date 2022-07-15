#include <any>
#include "Print.h"

int MAIN32()
{
	std::any data;

	data = 228;
	data = "rosnia - nahui";

	std::any_cast<std::string>(data); // here we cast any to a string

	return 0;
}