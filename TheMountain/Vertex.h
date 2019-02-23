#pragma once

class Vertex
{
private:
	int x, y, z;
public:
	Vertex()=default;
	Vertex(int, int, int);
	int GetX();
	int GetY();
	int GetZ();
	friend std::ostream& operator<<(std::ostream& out, Vertex& obj);
};