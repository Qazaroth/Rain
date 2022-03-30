#include "Drop.h"

// Private

// Public
Drop::Drop(sf::RenderWindow &window)
{
	reinit(window);
}
Drop::~Drop() {}

void Drop::reinit(sf::RenderWindow &window)
{
	sf::Vector2u size = window.getSize();

	this->x = Utils::getRandomNumber(0, size.x);
	this->len = Utils::map(this->z, 0, 20, 10, 20);
	this->yspeed = Utils::map(this->z, 0, 20, 5, 15);
}

void Drop::fall(sf::RenderWindow &window)
{
	sf::Vector2u size = window.getSize();

	this->y += this->yspeed;
	this->yspeed += 0.05;

	if (this->y > size.y)
	{
		this->y = Utils::getRandomNumber(-500, -50);
		this->yspeed = Utils::map(this->z, 0, 20, 5, 15);
	}
}

void Drop::show(sf::RenderWindow &window)
{
	sf::Vertex line[] = 
	{
		sf::Vector2f(this->x, this->y),
		sf::Vector2f(this->x, this->y + this->len)
	};

	for (int i = 0; i < sizeof(line) / sizeof(sf::Vertex); i++)
	{
		line[i].color = sf::Color(138, 43, 226, 255);
	}

	window.draw(line, 2, sf::Lines);
}