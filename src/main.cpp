#include <SFML/Graphics.hpp>

#include "FPSTimer.h"
#include "Drop.h"

#define FRAMECAP 60
#define RAIN_DROPS_COUNT 500

std::string TITLE = "Rain C++";
sf::Uint32 styleFlag = sf::Style::Default;

FPSTimer timer;
float timerCounter = 0.0f;
unsigned int frames = 0;

std::vector<Drop> drops;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), TITLE, styleFlag);
	window.setFramerateLimit(FRAMECAP);

	drops.resize(RAIN_DROPS_COUNT);
	for (int i = 0; i < drops.size(); i++)
	{
		drops[i].reinit(window);
	}

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color(230, 230, 250, 255));
		for (int i = 0; i < drops.size(); i++)
		{
			drops[i].fall(window);
			drops[i].show(window);
		}
		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		frames++;
		if (timer.elapsed() - timerCounter > 1.0f)
		{
			timerCounter += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}

	return 0;
}