// This example will use SFML libraries to implement
// the game of Pong

// History: 4/8 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include "Ball.h"
#include "Paddle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	Ball b((float)window.getSize().x / 4, sf::Color(sf::Color::Blue), sf::Vector2f(0,0));

	Paddle p1(*(new sf::Vector2f(-10, -10)), *(new sf::Color(sf::Color::White)), *(new sf::Vector2f(window.getSize().x/50, window.getSize().y/4)));

	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}