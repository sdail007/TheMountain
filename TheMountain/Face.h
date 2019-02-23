#pragma once
#include "Vertex.h"

class Face
{
private:
	Vertex a;
	Vertex b;
	Vertex c;

	//TODO: Save neighbor faces
public:
	//Face(Vertex, Vertex, Vertex);
	Face(const Vertex&, const Vertex&, const Vertex&);
	friend std::ostream& operator<<(std::ostream&, Face);
};
