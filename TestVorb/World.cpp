#include "World.h"


World::World() {
	srand(time(NULL));
	this->board = new IField**[Constants::SIZE];
	for (int i = 0; i < Constants::SIZE; i++) {
		this->board[i] = new IField*[Constants::SIZE];
		for (int k = 0; k < Constants::SIZE; k++) {
			IField* newField;
			int cointoss = rand() % 2;

			cointoss ? newField = new RecurringField() : newField = new PlainField();

			this->board[i][k] = newField;
		}
	}
}

World::~World() {
	for (int i = 0; i < Constants::SIZE; i++) {
		for (int k = 0; k < Constants::SIZE; k++) {
			delete this->board[i][k];
		}
		delete this->board[i];
	}
	delete this->board;
}

void World::printWorld() {
	for (int i = 0; i < Constants::SIZE; i++) {
		for (int k = 0; k < Constants::SIZE; k++) {
			this->board[i][k]->displayField();
		}
		std::cout << "\n";
	}
}

bool World::fieldIsPlain(int x, int y) {
	return this->board[y][x]->isPlain();
}

void World::replacePlain(IField* currentField) {
	bool foundPlain = false;
	int randX = 0;
	int randY = 0;
	while (!foundPlain) {
		randX = rand() % Constants::SIZE;
		randY = rand() % Constants::SIZE;
		if (fieldIsPlain(randX, randY)) {
			delete this->board[randY][randX];
			this->board[randY][randX] = currentField;
			foundPlain = true;
		}
	}
}

void World::executeField(int x, int y) {
	if (x > Constants::SIZE || x < 0)
		throw std::invalid_argument("x out of bounds");
	if (y > Constants::SIZE || y < 0)
		throw std::invalid_argument("y out of bounds");
	IField* currentField = this->board[y][x];
	if (currentField->execute()) {
		if (currentField->getPoints() > 0) {
			replacePlain(currentField);
			this->board[y][x] = new PlainField();
		}
		else {
			delete this->board[y][x];
			this->board[y][x] = new PlainField();
		}
	}
}

bool World::isEmpty() {
	for (int i = 0; i < Constants::SIZE; i++) {
		for (int k = 0; k < Constants::SIZE; k++) {
			if (!this->board[i][k]->isPlain())
				return false;
		}
	}

	return true;
}