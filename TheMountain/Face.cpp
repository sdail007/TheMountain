#include "pch.h"

#include <math.h>
#define PI 3.14159265

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

Vertex Face::GetCenter() const
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

float Face::Grade() const
{
	//create 2 vectors from the face
	Vector ab = vertices[0] - vertices[1];
	Vector ac = vertices[0] - vertices[2];
	
	//Calculate normal vector of the face
	Vector normal = ac.CrossProduct(ab);

	//normal vector of the horizontal plane
	Vector up = Vector(0.0f, 0.0f, 1.0f);
	
	//find the angle between the two normal vectors
	float dotProduct = normal.DotProduct(up);
	float magnitudes = normal.Magnitude() * up.Magnitude();
	
	float div = dotProduct / magnitudes;
	float angle = acosf(div) * 180.0f / PI;

	return angle;
}

float Face::FindArea() const
{
	Vector ab = vertices[0] - vertices[1];
	Vector ac = vertices[0] - vertices[2];

	float a = (ab.GetJ() * ac.GetK()) - (ab.GetK() * ac.GetJ());
	float b = (ab.GetK() * ac.GetI()) - (ab.GetI() * ac.GetK());
	float c = (ab.GetI() * ac.GetJ()) - (ab.GetJ() * ac.GetI());

	float inner = powf(a, 2.0f) + powf(b, 2.0f) + powf(c, 2.0f);

	float area = 0.5f * sqrtf(inner);

	return area;
}

Face* Face::Subdivide() const
{
	static Face faces[3];

	Vertex center = GetCenter();

	//a ,b, c, center
	Face one = Face(a, b, center);
	Face two = Face(a, c, center);
	Face three = Face(b, c, center);

	faces[0] = one;
	faces[1] = two;
	faces[2] = three;

	return faces;
}

std::ostream& operator<<(std::ostream& out, Face obj)
{
	out << "[(" << obj.a << "), (" << obj.b << "), (" << obj.c << ")]";
	return out;
}