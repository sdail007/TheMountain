#pragma once

class Vector
{
private:
	float i, j, k;
public:
	float GetI() const;
	float GetJ() const;
	float GetK() const;

	Vector(float, float, float);
	Vector() = default;
	float Magnitude() const;
	Vector CrossProduct(const Vector& b);
	float DotProduct(const Vector& b);

	friend std::ostream& operator<<(std::ostream&, Vector&);
};