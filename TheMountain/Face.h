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
	Face() = default;
	Face(const Vertex&, const Vertex&, const Vertex&);
	Vertex GetCenter() const;
	float Grade() const;
	float FindArea() const;
	Face* Subdivide() const;

	friend std::ostream& operator<<(std::ostream&, Face);

};