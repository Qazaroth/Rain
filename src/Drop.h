#pragma once

#include "Utils.h"

#include <SFML/Graphics.hpp>

class Drop
{
private:
	float x = 0;
	float y = Utils::getRandomNumber(-500, -50);
	float yspeed = 0;
	float z = Utils::getRandomNumber(0, 20);
	float len = 10;
public:
	Drop() {}
	Drop(sf::RenderWindow &window);
	~Drop();

	void reinit(sf::RenderWindow &window);

	void fall(sf::RenderWindow &window);
	void show(sf::RenderWindow &window);
};

