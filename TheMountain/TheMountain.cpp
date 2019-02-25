// TheMountain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SubdivideFaces(Face& face, vector<Face>& added, vector<Face>& removed);

int main()
{
	cout << "Build a mountain!" << endl;

	Vertex a = Vertex(0, 0, 0);
	Vertex b = Vertex(0, 100, 0);
	Vertex c = Vertex(100, 0, 0);
	Vertex d = Vertex(100, 100, 0);

	Vertex peak = Vertex(50, 50, 50);

	Face north = Face(b, d, peak);
	Face east = Face(a, b, peak);
	Face south = Face(a, c, peak);
	Face west = Face(c, d, peak);

	Vertex centerNorth = north.GetCenter();
	Vertex centerEast = east.GetCenter();
	Vertex centerSouth = south.GetCenter();
	Vertex centerWest = west.GetCenter();

	cout << "Center of North is " << centerNorth << endl;
	cout << "Center of South is " << centerSouth << endl;
	cout << "Center of East is " << centerEast << endl;
	cout << "Center of West is " << centerWest << endl;

	float nGrade = north.Grade();
	float sGrade = south.Grade();
	float eGrade = east.Grade();
	float wGrade = west.Grade();

	cout << "North has a grade of " << nGrade << endl;
	cout << "South has a grade of " << sGrade << endl;
	cout << "East has a grade of " << eGrade << endl;
	cout << "West has a grade of " << wGrade << endl;

	float nArea = north.FindArea();
	float sArea = south.FindArea();
	float eArea = east.FindArea();
	float wArea = west.FindArea();

	cout << "North has an area of " << nArea << endl;
	cout << "South has an area of " << sArea << endl;
	cout << "East has an area of " << eArea << endl;
	cout << "West has an area of " << wArea << endl;

	//Subdivide each face of the mountain.
	vector<Face> mountainFaces = vector<Face>();
	mountainFaces.push_back(north);
	mountainFaces.push_back(east);
	mountainFaces.push_back(south);
	mountainFaces.push_back(west);

	vector<Face> added = vector<Face>();
	vector<Face> removed = vector<Face>();

	for (std::vector<Face>::iterator i = mountainFaces.begin(); i != mountainFaces.end(); i++)
	{
		Face f = *i;
		SubdivideFaces(f, added, removed);
	}

	cout << added.size() << " faces added" << endl;

	ofstream file;
	file.open("butts.txt");

	for (std::vector<Face>::iterator i = mountainFaces.begin(); i != mountainFaces.end(); i++)
	{
		Face f = *i;
		file << f << endl;
	}

	for (std::vector<Face>::iterator i = added.begin(); i != added.end(); i++)
	{	
		Face f = *i;
		file << f << endl;
	}

	file.close();

	string input;
	getline(cin, input);
}

//Get a face <-- lol
//	subdivide the face
//	get 3 faces
//		foreach face
//			check area of face
//			if area within threshold
//				call this method

void SubdivideFaces(Face& face, vector<Face>& added, vector<Face>& removed)
{
	cout << "subdividing a face ClappyHype " << endl;
	Face* subdivisions = face.Subdivide();

	removed.push_back(face);

	for(int i = 0; i <= 2; i++)
	{
		Face subdivision = subdivisions[i];
		
		added.push_back(subdivision);
		cout << added.size() << " faces added so far" << endl;

		float area = subdivision.FindArea();
		std::cout << "Subdivision " << i << " has an area of " << area << std::endl;

		if(area > 250.0f)
		{
			SubdivideFaces(subdivision, added, removed);
		}
	}
}