#include <iostream>

#pragma region ARRAY
#include <array>

template<typename T, size_t S>
class Array
{
public:
	constexpr int Size() const { return S; } //can be evaluated at the compile time (constexpr)

	T& operator[](size_t index)
	{
		if (!index < 5) //extra check slower but safer (optional)
			__debugbreak; // breaking the compiler

		return Data[index];
	}
	const T& operator[](size_t index) const { return Data[index]; }

	T* GetData() { return Data; }
	const T* GetData() const { return Data; }

private:
	T Data[S];
};

void ARRAY()
{
#pragma region EX1 // alloc of the array
	//if u need an array in the scope use stack alloc (faster)
	int array[5]; //stack alloc

	int* heapArray = new int[5]; // heap alloc
	delete[] heapArray; // need to be deleted
#pragma endregion

#pragma region EX2 // std array

	std::array<int, 10> collection;

	for (int i = 0; i < collection.size(); i++)
		collection[i];

#pragma endregion


#pragma region EX3 // custom array (quasi-dynamicaly sized)
	// just make my own copy of std array

	int size = 5;

	Array<int, 5> data;

	const auto& arrayRef = data;

	static_assert(data.Size() < 10, "Size is too large"); //checks if size is below 10

	memset(data.GetData(), 0, data.Size() * sizeof(int)); //setting all int of an array to 0

	for (int i = 0; i < data.Size(); i++)
	{
		data[i] = 2; // needs & and [] operator to work
		arrayRef[i]; // needs const [] operator to work

	}
#pragma endregion
}
#pragma endregion

#pragma region VECTOR
#include <vector>

template<typename T>
class Vector
{
public:
	Vector()
	{
		ReAlloc(2);
	}

	~Vector()
	{
		::operator delete(Data, Campacity * sizeof(T));
	}

	void PushBack(const T& value)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		Data[Size] = value;
		Size++;
	}

	void PushBack(T&& value)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		Data[Size] = std::move(value);
		Size++;
	}

	template<typename... Args> //variatic template
	T& EmplaceBack(Args&&... args)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		new(&Data[Size]) T(std::forward<Args>(args)...); // doen`t provide MoveDestroy action

		//Data[Size] = T(std::forward<Args>(args)...); provides Move/Destroy action

		return Data[Size++];
	}

	void PopBack()
	{
		if (Size > 0)
		{
			Size--;
			Data[Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < Size; i++)
			Data[i].~T();

		Size = 0;
	}

	const T& operator[](size_t index) const
	{
		return Data[index];
	}

    T& operator[](size_t index) 
	{
		return Data[index];
	}

	size_t GetSize() const { return Size; }

private:
	void ReAlloc(size_t newCampacity)
	{
		//T* newBlock = new T[newCampacity]; // allocate a new block of memory (calls a constructor)

		T* newBlock = (T*)::operator new(newCampacity * sizeof(T)); //does not call an constructor

		if (newCampacity < Size)
			Size = newCampacity;

		for (size_t i = 0; i < Size; i++)
			Data[i].~T();

		for (size_t i = 0; i < Size; i++) // move old elements into a new block
			newBlock[i] = std::move(Data[i]);

		//delete[] Data; calls an destructor thus we delete already deleted obj

		::operator delete(Data, Campacity * sizeof(T)); //does not call an destructor

		Data = newBlock;
		Campacity = newCampacity;
	}

private:
	T* Data = nullptr;

	size_t Size = 0;
	size_t Campacity = 0;
};

struct Vector3
{
	float x = .0f, y = .0f, z = .0f;

	int* memBlock;

	Vector3(){ memBlock = new int[5]; }
	Vector3(float scalar) : x(scalar), y(scalar), z(scalar) 
	{
		memBlock = new int[5];
	}

	Vector3(float x, float y, float z) : x(x), y(y), z(z)
	{
		memBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete; //deleting the copy constructor cuz we don`t call it anymore
	/*
	Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copy \n";
	}*/

	Vector3(Vector3&& other) : x(other.x), y(other.y), z(other.z)
	{
		memBlock = other.memBlock;
		other.memBlock = nullptr;

		std::cout << "Move \n";
	}

	~Vector3() 
	{
		std::cout << "Destroy \n";

		delete[] memBlock;
	}

	Vector3& operator=(const Vector3& other) = delete;
/*	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copy \n";

		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}*/

	Vector3& operator=(Vector3&& other)
	{
		memBlock = other.memBlock;
		other.memBlock = nullptr;

		std::cout << "Move \n";

		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}
};

static void PrintVector(const Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.GetSize(); i++)
		std::cout << vector[i].x << vector[i].y << vector[i].z << std::endl;
}

void VECTOR()
{
	{
		Vector<Vector3> vector;
		vector.PushBack(Vector3());
		vector.PushBack(Vector3(1, 2, 3));
		vector.EmplaceBack(6, 6, 6);

		PrintVector(vector);

		vector.PopBack();

		PrintVector(vector);

		vector.Clear();

		vector.PushBack(Vector3(1, 4, 8));
		vector.PushBack(Vector3(8, 1, 4));
		vector.PushBack(Vector3(8, 8, 1));
		vector.PushBack(Vector3(4, 8, 8));

		PrintVector(vector);
	}
}
#pragma endregion


int MAIN41()
{
	//ARRAY();

	VECTOR();

	return 0;
}