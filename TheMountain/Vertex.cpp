#include "pch.h"

Vertex::Vertex(float x, float y, float z)
{
	Vertex::x = x;
	Vertex::y = y;
	Vertex::z = z;
}

float Vertex::GetX() const
{
	return x;
}

float Vertex::GetY() const
{
	return y;
}

float Vertex::GetZ() const
{
	return z;
}

std::ostream& operator<<(std::ostream& out, Vertex& obj)
{
	out << obj.x << "," << obj.y << "," << obj.z;
	return out;
}

Vector operator-(const Vertex& a, const Vertex& b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}