#include <iostream>

struct Vector2
{
	float x, y;
};

int MAIN9()
{
#pragma region AllocationOnTheStack // deleted automaticaly when scope comes to an end
	int value = 5; 

	int array[5];

	Vector2 vector2;
#pragma endregion

#pragma region AllocationOnTheHeap //need to be deleted

	int* valuePtr = new int; 
	*valuePtr = 5;

	int* arrayPtr = new int[5];

	Vector2* vector2Ptr = new Vector2();

	delete valuePtr;
	delete[] arrayPtr;
	delete vector2Ptr;
#pragma endregion

	return 0;
}