#include <iostream>

/* Union kinda the same as struct & class but has ONLY one member*/

#define END_LINE "\n";
//find in Macros.cpp

struct Vector2
{
	float x, y;
};

#pragma region WithoutUnion //example of extracting Vector2 from Vector4 without union
struct Vector4WOU
{
	float x, y, z, t;

	Vector2& Extract2DVector()
	{
		return *(Vector2*)&x; //find in TypePunning.cpp
	}
};
#pragma endregion

#pragma region WithUnion //example of extracting Vector2 from Vector4 by using union
struct Vector4UU
{
	union
	{
		struct // a very first member of a union
		{
			float x, y, z, t;
		};
		struct // a second member (ocupies same space as first one)
		{
			Vector2 xAndY, zAndT;
		};
	};
};
#pragma endregion


void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << "," << vector.y << END_LINE;
}

template<typename T>
static void Print3(T value)
{
	std::cout << value << END_LINE;
}

int MAIN21()
{
#pragma region  GeneralExample
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;

	Print3(u.a); // print a as float
	Print3(u.b); // print b (b = a) value as a (float) type
#pragma endregion

#pragma region SecondExample
	Vector4UU vectorUsingUnions = { 1.0f, 4.0f, 8.0f, 8.0f };
	PrintVector2(vectorUsingUnions.xAndY);

	Vector4WOU vectorWithoutUnions = { 1.0f, 4.0f, 8.0f, 8.0f }; 
	PrintVector2(vectorWithoutUnions.Extract2DVector());
#pragma endregion

	return 0;
}