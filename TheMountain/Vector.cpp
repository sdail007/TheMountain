#include "pch.h"
#include <math.h>

float Vector::GetI() const
{
	return i;
}

float Vector::GetJ() const
{
	return j;
}

float Vector::GetK() const
{
	return k;
}

Vector::Vector(float i, float j, float k)
{
	Vector::i = i;
	Vector::j = j;
	Vector::k = k;
}

float Vector::Magnitude() const
{
	int a = powf(i, 2.0f) + powf(j, 2.0f) + powf(k, 2.0f);
	int b = sqrtf(a);
	return b;
}

Vector Vector::CrossProduct(const Vector& b)
{
	float crossX = (j * b.GetK()) - (k * b.GetJ());
	float crossY = (k * b.GetI()) - (i * b.GetK());
	float crossZ = (i * b.GetJ()) - (j * b.GetI());

	return Vector(crossX, crossY, crossZ);
}

float Vector::DotProduct(const Vector& b)
{
	return i * b.GetI() + j * b.GetJ() + k * b.GetK();
}

std::ostream& operator<<(std::ostream& out, Vector& obj)
{
	out << "[" << obj.i << "," << obj.j << "," << obj.k << "]";
	return out;
}