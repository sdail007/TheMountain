#pragma once
#include "Vertex.h"

class Face
{
private:
	Vertex a;
	Vertex b;
	Vertex c;
	Vertex* vertices;

	//TODO: Save neighbor faces
public:
	//Face(Vertex, Vertex, Vertex);
	Face(const Vertex&, const Vertex&, const Vertex&);
	Vertex GetCenter();
	float Grade();

	friend std::ostream& operator<<(std::ostream&, Face);

};