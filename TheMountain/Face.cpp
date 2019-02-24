#include "pch.h"

#include <math.h>

Face::Face(const Vertex& a, const Vertex& b, const Vertex& c)
{
	Face::a = a;
	Face::b = b;
	Face::c = c;

	Face::vertices = new Vertex[3];
	Face::vertices[0] = a;
	Face::vertices[1] = b;
	Face::vertices[2] = c;
}

Vertex Face::GetCenter()
{
	float x1 = a.GetX();
	float x2 = b.GetX();
	float x3 = c.GetX();

	float y1 = a.GetY();
	float y2 = b.GetY();
	float y3 = c.GetY();

	float z1 = a.GetZ();
	float z2 = b.GetZ();
	float z3 = c.GetZ();

	float centerX = (x1 + x2 + x3) / 3.0f;
	float centerY = (y1 + y2 + y3) / 3.0f;
	float centerZ = (z1 + z2 + z3) / 3.0f;

	return Vertex(centerX, centerY, centerZ);	
}

float Face::Grade()
{
	//Cross Product
	Vector ab = vertices[0] - vertices[1];
	Vector ac = vertices[0] - vertices[2];
	
	Vector cross = ab.CrossProduct(ac);

	//a,b,c
	// dot product of a*b
	// dot product of a*c
	// average dot products

	return 0.0f;
}

std::ostream& operator<<(std::ostream& out, Face obj)
{
	out << "[(" << obj.a << "), (" << obj.b << "), (" << obj.c << ")]";
	return out;
}