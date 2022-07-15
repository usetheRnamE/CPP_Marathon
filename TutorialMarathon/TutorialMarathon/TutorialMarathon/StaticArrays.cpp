#include <iostream>
#include <array>

#define WAITANDRETURN std::cin.get();\
 return 0;// find in Macros.cpp

void PrintOLDArray(int* oldArray, unsigned int size) //here it`s an example how we can passed length of an OLD array
{
	for (size_t i = 0; i < size; i++){}
}

template <unsigned int SIZE> // find in Templates.cpp
void PrintSTDArray(const std::array<int, SIZE>& data) 
/*here I use templates cuz when we pass a std array we have to declare the size of it
and by using templates we can avoid specific size declaration 
for instance without templates we have to write smth like that: const std::array<int, 5>& data 
so if we change the size of an array we want to been passed to this function we have to change size of array in the function as well*/
{
	for (size_t i = 0; i < data.size(); i++) {} // and here we just passed array itself and call a "size" function
}

int MAIN12()
{
#pragma region CuttingEdgeArrayDeclaration // standart lib array
	std::array< int, 5> data; 

	data[0] = 2;
	data[4] = 1;
	//data[5] = 228; // will cause an error in debug mode because of bound checking feature howecer in release mode it`s will be OK

	PrintSTDArray<data.size()> (data); //size actually don`t return a variable it`s just return a 5 (in this example) so this is pretty fast
#pragma endregion

#pragma region OldArrayDeclarition
	int dataOld[5];

	dataOld[0] = 0;
	dataOld[4] = 1;
	//dataOld[5] = 3; // will override data that we don`t allocated
#pragma endregion

	/*
	 !!! In context of a memory they both use a stack storage
	std array as fast as old one
	*/

		WAITANDRETURN
}