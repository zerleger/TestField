#pragma once
#include <stdlib.h> 
#include <time.h>
#include <stdexcept>

#include "Field.h"
#include "Constants.h"
#include "RecurringField.h"
#include "PlainField.h"

class Field;


class World
{
public:
	World();
	~World();
	void printWorld();
	void executeField(int x, int y);
	void replacePlain(IField* currentField);
	bool fieldIsPlain(int x, int y);
	bool isEmpty();
private:
	IField*** board;
};

