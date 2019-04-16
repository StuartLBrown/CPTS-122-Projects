// This example will use SFML libraries to implement
// the game of Pong

// History: 4/8 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include "Ball.h"
#include "Paddle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	Ball b((float)window.getSize().x / 50, sf::Color(sf::Color::Blue), sf::Vector2f(100,100));

	Paddle p1(*(new sf::Vector2f(0,window.getSize().y/2)), sf::Color::White, *(new sf::Vector2f(window.getSize().x/50, window.getSize().y/5)));
	Paddle p2(*(new sf::Vector2f(window.getSize().x-window.getSize().x/50, window.getSize().y / 2)), sf::Color::White, *(new sf::Vector2f(window.getSize().x / 50, window.getSize().y / 5)));

	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&p1.getPosition().y>=0)
				p1.move(0, -5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&(p1.getPosition().y+p1.getSize().y<=window.getSize().y))
				p1.move(0, 5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && p2.getPosition().y >= 0)
				p2.move(0, -5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (p2.getPosition().y + p2.getSize().y <= window.getSize().y))
				p2.move(0, 5);
		}

		window.clear();
		window.draw(b);
		window.draw(p1);
		window.draw(p2);
		window.display();
	}

	return 0;
}