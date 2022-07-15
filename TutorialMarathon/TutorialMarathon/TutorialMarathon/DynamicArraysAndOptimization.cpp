#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z): x(x), y(y), z(z){}

	Vertex(const Vertex& other)
	{
		std::cout << "Copied" << "\n";

		memcpy(this, &other, sizeof(Vertex));
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) //custom printing function
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z << "\n";
	return stream;
}

void Function(std::vector<Vertex>& verticesRef) //very I mean VERY importent to send vectors as ref to avoid copying
{
	verticesRef.clear(); // clear all members

	if(!verticesRef.empty()) //always false
	   verticesRef.erase(verticesRef.begin() + 1); //erase 2th element
}

int MAIN5()
{
	std::vector<Vertex> vertices; //implementation of vector (dynamic array) pretty easy tho
	
	//NOTE: std::vector<Vertex> vertices(3); -> this line CREATE 3 empty objs

	vertices.reserve(3); //reserving place for 3 obj and make 3 copies, without this we make a 6 copies

	/*vertices.push_back(Vertex(2, 2, 8)); //make a copy
	vertices.push_back(Vertex(3, 3, 9));  //make a copy
	vertices.push_back(Vertex(4, 4, 6));  //make a copy*/
	
	// NOTE: in stead of push_back use emplace_back to dont make a copy at all

	vertices.emplace_back(2, 2, 8); //DONT make a copy
	vertices.emplace_back(3, 3, 9);  //DONT make a copy
	vertices.emplace_back(4, 4, 6);  //DONT make a copy

	for (const Vertex& v : vertices) // goes throught all members of vertices
		std::cout << v;

	Function(vertices);

	std::cin.get();
	return 0;
}