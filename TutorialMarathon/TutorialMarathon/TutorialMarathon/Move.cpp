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

	String(String&& other) noexcept // move constructor ( use R values (temporary values) )
	{
		printf("Moved \n");

		size = other.size;
		data = other.data; // pointing to the same block of data

		other.size = 0;
		other.data = nullptr;
	}

	String& operator=(String&& other) noexcept //The "=" operator
	{
		printf("Moved \n");

		if (this != &other)
		{
			delete[] data; // delete current data before assignment to avoid memory leak

			size = other.size;
			data = other.data; // pointing to the same block of data

			other.size = 0;
			other.data = nullptr;
		}

		return *this;
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

class EntityMove // use move constructor
{
public:
	EntityMove(String&& name) : Name(std::move(name)) {} // move operato cast I value to R value

	void Print()
	{
		Name.Print();
	}

private:
	String Name;
};

int MAIN40()
{
	EntityMove entityMove(String("Suck some dicks"));
	entityMove.Print();

	String string = "dicks";


	String destSimpCast = (String&&)string; // shity piece of shity shit
	String destMoveCast = std::move(string); // gigachad option

	destMoveCast = std::move(string); // needs an "=" operator to work
	destMoveCast = std::move(destMoveCast); // needs an if statement in an "=" operator to work

	destMoveCast.Print();

	std::cin.get();

	return 0;
}