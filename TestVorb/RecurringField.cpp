#include "RecurringField.h"

RecurringField::RecurringField() {
	int random = rand() % 3 + 1;
	this->points = random;
	this->display = 'O';
}

bool RecurringField::execute() {
	this->points -= 1;
	return true;
}

int RecurringField::getPoints() {
	return this->points;
}


void RecurringField::displayField() {
	std::cout << this->display << " ";
}

bool RecurringField::isPlain() {
	return false;
}