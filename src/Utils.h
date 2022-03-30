#pragma once

#include <iostream>

class Utils
{
public:
	inline int static getRandomNumber(int min, int max)
	{
		return min + (std::rand() % (max - min + 1));
	}
	int static map(float value, float start1, float stop1, float start2, float stop2)
	{
		float outgoing = start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
		return outgoing;
	}
};