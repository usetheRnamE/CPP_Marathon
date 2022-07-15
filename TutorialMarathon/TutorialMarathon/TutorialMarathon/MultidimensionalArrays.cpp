#include <iostream>

int MAIN18()
{
#pragma region 1DArray // how to use it like a multi dim array

	int* array1D = new int[50 * 50]; //in this case we use it like a 2D array

	for (int x = 0; x < 50; x++) // a lot faster than 2d array
		for (int y = 0; y < 50; y++)
			array1D[x + y * 50] = 1488;

#pragma endregion


#pragma region 2DArray  // declaration of a 2D array
	int** array2D = new int* [50];

	for (int i = 0; i < 50; i++)
		array2D[i] = new int[50];

	for (int i = 0; i < 50; i++)
	    delete[] array2D[i]; // deleting a 2d array;
#pragma endregion

#pragma region 3DArray // declaration of a 3D array
	int*** array3D = new int** [50]; 

	for (int i = 0; i < 50; i++)
	{
		array3D[i] = new int* [50];
		for (int k = 0; k < 50; k++)
		{
			array3D[i][k] = new int[50];
		}
	}

	array3D[0][0][0] = 0; // setting a very first value to a 3d array
#pragma endregion


	


	std::cin.get();
	return 0;
}