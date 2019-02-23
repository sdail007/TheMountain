#include "pch.h"

/*Face::Face(Vertex a, Vertex b, Vertex c)
{
	Face::a = a;
	Face::b = b;
	Face::c = c;
}*/

Face::Face(const Vertex& a, const Vertex& b, const Vertex& c)
{
	Face::a = a;
	Face::b = b;
	Face::c = c;
}

std::ostream& operator<<(std::ostream& out, Face obj)
{
	out << "[(" << obj.a << "), (" << obj.b << "), (" << obj.c << ")]";
	return out;
}