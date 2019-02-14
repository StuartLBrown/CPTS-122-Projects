#include "rectangle.h"
//what class this function belongs to
Rectangle::Rectangle(int length, int width) {
	setLength(length);
	setWidth(width);
}

Rectangle::Rectangle(Rectangle &r) {
	length = r.length;
	width = r.width;
}

Rectangle::~Rectangle() {
	std::cout << length << "\n" << width << "\n";
	std::cout << "inside deconstructor\n";
}

int Rectangle::getLength() {
	return length;
}
int Rectangle::getWidth() {
	return width;
}
void Rectangle::setLength(int length) {
	if (length >= 0)
		Rectangle::length = length;
	else
		Rectangle::length = 0;
}
void Rectangle::setWidth(int width) {
	if (width >= 0)
		Rectangle::width = width;
	else
		Rectangle::width = 0;
}
void Rectangle::printRectangle(void) {
	std::cout << "Length: " << length << "\nWidth: " << width << std::endl;
}
void printRectangle(Rectangle r) {//copy of a rectangle is made
	r.printRectangle();
}

std::ostream &operator<<(std::ostream &lhs, Rectangle &rhs) {
	lhs << rhs.getLength() << " " << rhs.getWidth();
	return lhs;
}
