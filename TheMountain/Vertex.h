#pragma once

class Vertex
{
private:
	float x, y, z;
public:
	Vertex()=default;
	Vertex(float, float, float);
	float GetX();
	float GetY();
	float GetZ();
	friend std::ostream& operator<<(std::ostream& out, Vertex& obj);
	//friend Vector operator-(const Vertex&, const Vertex&);
};