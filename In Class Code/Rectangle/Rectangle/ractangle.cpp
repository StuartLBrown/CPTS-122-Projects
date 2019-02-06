#include "rectangle.h"
//what class this function belongs to
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