#include "Print.h"
#include <fstream>
#include <optional>

#pragma region Ex1 //empty string method
std::string ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		//read file

		stream.close();
		return result;
	}

	return std::string();
}

void Action1()
{
	std::string data = ReadFileAsString("deadrusso.txt");
	if (data != "")
	{

	}
}
#pragma endregion

#pragma region Ex2 //boolean method
std::string ReadFileAsString2(const std::string& filepath, bool& outSucccess)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		//read file

		stream.close();

		outSucccess = true;

		return result;
	}

	outSucccess = false;
	return std::string();
}

void Action2()
{
	bool fileOpenedSuccessfully;

	std::string data = ReadFileAsString2("deadrusso.txt", fileOpenedSuccessfully);
	if (fileOpenedSuccessfully)
	{

	}
}
#pragma endregion

#pragma region Ex3(Optional) // C++ 17(and greater) feature
std::optional<std::string> ReadFileAsString3(const std::string& filepath)
{
	std::ifstream stream(filepath);

	if (stream)
	{
		std::string result;
		//read file

		stream.close();
		return result;
	}

	return {};
}

void Action3()
{
	std::optional<std::string> data = ReadFileAsString("deadrusso.txt");


	std::string value = data.value_or("Not present"); // will  return either value or text in brackets

	if (data)
	{
		prt::Print("File has been read successfully");
	}
	else
	{
		std::string& string = *data; // or data.value()
		prt::Print("File has not been opened");
	}
}
#pragma endregion

int MAIN29()
{
	Action1();
	Action2();
	Action3();

	return 0;
}