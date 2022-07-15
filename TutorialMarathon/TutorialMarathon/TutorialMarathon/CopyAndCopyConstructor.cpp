#include <iostream>
#include <string>

class String
{
private:
    char* mBuffer;
	unsigned int mSize; //always plural

public:
	String(const char* string)
    {
	 mSize = strlen(string);
	 //mSize = strcpy(string); //includes the null termination characters

	 mBuffer = new char[mSize + 1]; // use mSize + 1 or just mSize and strcpy
	
	 memcpy(mBuffer, string, mSize);

	 mBuffer[mSize] = 0; // remove if use strcpy
    }

#pragma region MemCopyConstructors

	//String(const String& other); //mem copy default copy constructor (default = boring shit)

	//String(const String& other) :mBuffer(other.mBuffer), mSize(other.mSize) {} // does the same as default but u can treat to it like to own child

	/*String(const String& other)		 //does the same as 2 previous constructors but cooler
	{
		memcpy(this, &other, sizeof(String));
	}*/

	String(const String& other) : mSize(other.mSize) //deeeeeeeeep copy (sounds cool)
	{
		std::cout << "copy has been made" << "\n";

		mBuffer = new char[mSize + 1];

		memcpy(mBuffer, other.mBuffer, mSize + 1);
	}

	//String(const String& other) = delete; // if we dont wanna allow copying
#pragma endregion


	~String()
	{
		delete[] mBuffer; //use delete[] for an arrays and delete for other stuff
	}

public:
	char& operator[](unsigned int index) //custom operator that returns a specific char in mBuffer array (meanwhile ruskie sosyt)
	{
		return mBuffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string); // makes code more efficient
};

std::ostream& operator<<(std::ostream& stream, const String& string) //custom operator
{
	//stream << string.GetBuffer(); -> without <friend> keyword

	stream << string.mBuffer; // with <friend> keyword

	return stream;
}

void PrintString(const String& string) //whithout <&> we will copying String class every time we call this function 
{
	std::cout << string << "\n";
}

#pragma region DifferenceBTWNPtrAndValues
struct Vector3
{
	float x, y, z;
};

int MAIN3() //rewrite to main to make this function work
{
#pragma region CopyValue
	Vector3 a = { 2, 2, 8 };
	Vector3 b = a;
	b.x = 5; // here we just modify b.x value
#pragma endregion

#pragma region CopyRef
	Vector3* A = new Vector3();
	Vector3* B = A;

	B->x = 5; // here we change both A and B x value
#pragma endregion

#pragma endregion

#pragma region StringExample
	String string = "Rashusta porvalo) (bukvalno) ";
	String secondOne = string; //we use copying constructor in order to prevent copying just mem adress and calling destructor twice

	secondOne[0] = 'r'; //rashust must start from the lowest char ever exist 

	PrintString(string);
	PrintString(secondOne);
#pragma endregion

	return 0;
	std::cin.get();
}


