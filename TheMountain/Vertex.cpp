#include "pch.h"

Vertex::Vertex(int x, int y, int z)
{
	Vertex::x = x;
	Vertex::y = y;
	Vertex::z = z;
}

int Vertex::GetX() 
{
	return x;
}

int Vertex::GetY()
{
	return y;
}

int Vertex::GetZ()
{
	return z;
}

std::ostream& operator<<(std::ostream& out, Vertex& obj)
{
	out << obj.x << "," << obj.y << "," << obj.z;
	return out;
}