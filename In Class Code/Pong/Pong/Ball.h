#include <SFML\Graphics.hpp>
#pragma once
class Ball : public sf::CircleShape {
private:
public:
	Ball(float radius, sf::Color &c, sf::Vector2f &startPos) : CircleShape(radius) {
		this->setFillColor(c);
		this->setPosition(startPos);
	}
};