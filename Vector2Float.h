#pragma once
#include <iostream>

class Vector2Float
{
public:
	Vector2Float(float _x, float _y); //constructor

	void printVectors() //very useful method to have for debugging things related to vectors
	{
		std::cout << x << ", " << y << std::endl;
	};

	float x, y; // variables representing the x and the y axis
};

