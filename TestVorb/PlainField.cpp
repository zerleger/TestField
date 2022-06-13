#include "PlainField.h"

PlainField::PlainField() {
	this->points = 0;
	this->display = '_';
}

bool PlainField::execute() {
	return false;
}

int PlainField::getPoints() {
	return this->points;
}

void PlainField::displayField() {
	std::cout << this->display << " ";
}

bool PlainField::isPlain() {
	return true;
}