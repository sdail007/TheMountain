#include "pch.h"

Vertex::Vertex(float x, float y, float z)
{
	Vertex::x = x;
	Vertex::y = y;
	Vertex::z = z;
}

float Vertex::GetX() 
{
	return x;
}

float Vertex::GetY()
{
	return y;
}

float Vertex::GetZ()
{
	return z;
}

std::ostream& operator<<(std::ostream& out, Vertex& obj)
{
	out << obj.x << "," << obj.y << "," << obj.z;
	return out;
}

//Vector operator-(const Vertex& a, const Vertex& b)
//{
//	return Vector(b.x - a.x, b.y - a.y, b.z - a.z);
//}