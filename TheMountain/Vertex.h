#pragma once

class Vertex
{
private:
	float x, y, z;
public:
	Vertex()=default;
	Vertex(float, float, float);
	float GetX() const;
	float GetY() const;
	float GetZ() const;
	friend std::ostream& operator<<(std::ostream& out, Vertex& obj);
	friend Vector operator-(const Vertex&, const Vertex&);
};