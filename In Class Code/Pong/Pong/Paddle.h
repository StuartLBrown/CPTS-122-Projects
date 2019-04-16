#include <SFML/Graphics.hpp>
class Paddle : public sf::RectangleShape {
private:

public:
	Paddle(sf::Vector2f &pos, const sf::Color &color, sf::Vector2f &size) : sf::RectangleShape(size) {
		this->setPosition(pos);
		this->setFillColor(color);
	}
};