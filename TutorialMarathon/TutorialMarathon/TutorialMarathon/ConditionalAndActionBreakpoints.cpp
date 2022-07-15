#include <iostream>

int MAIN26()
{
	double result = 1;

	for (int i = 0; i < 3; i++)
		result *= i + pow(result, i) / (i + 1); //tap on breakpoint -> action, to make an action breakpoint	

	for (int i = 0; i < 3; i++)
		result *= i + pow(result, i) / (i + 1); //tap on breakpoint -> condition, to make a condition breakpoint	

	return 0;
}