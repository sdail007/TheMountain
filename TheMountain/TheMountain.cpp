// TheMountain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout << "Build a mountain!" << std::endl; 

	Vertex a = Vertex(0, 0, 0);
	Vertex b = Vertex(0, 4, 0);
	Vertex c = Vertex(4, 4, 4);

	Face f = Face(a, b, c);

	std::cout << f << std::endl;

	Vertex center = f.GetCenter();
	std::cout << "Center of f: " << center << std::endl;

	Vector ab = a - b;
	Vector ac = a - c;

	Vector cross = ab.CrossProduct(ac);

	std::cout << ab << " cross " << ac << " is " << cross << std::endl;

	string input;
	getline(std::cin, input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
