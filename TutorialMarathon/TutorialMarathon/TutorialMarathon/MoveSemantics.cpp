#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created \n");

		size = strlen(string);
		data = new char[size];

		memcpy(data, string, size);
	}

	String(const String& other) // copy constructor ( + 1 allocation on the heap )
	{
		printf("Copied \n");

		size = other.size;
		data = new char[size];

		memcpy(data, other.data, size);
	}

	String(String&& other) noexcept // move constructor ( use R values (temporary values) )
	{
		printf("Moved \n");

		size = other.size;
		data = other.data; // pointing to the same block of data

		other.size = 0;
		other.data = nullptr;
	}

	~String()
	{
		delete data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < size; i++)	
			printf("%c", data[i]);

		printf("\n");
		
	}

private:
	char* data;
	uint32_t size;
};

class EntityCopy // use copy constructor
{
public:
	EntityCopy(const String& name) : Name(name) {}

private:
	String Name;
};

class EntityMove // use move constructor
{
public:
	EntityMove(String&& name) : Name(std::move(name)) {} // find in Move.cpp

private:
	String Name;
};

int MAIN39()
{
	EntityCopy entityCopy(String("Suck some dicks"));
	EntityMove entityMove(String("Suck some dicks"));

	std::cin.get();

	return 0;
}