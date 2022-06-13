#pragma once
#include "Field.h"
#include <stdlib.h> 
#include <time.h>     


class RecurringField : public IField
{
public:
	RecurringField();
	bool execute() override;
	void displayField() override;
	int getPoints() override;
	bool isPlain() override;
private:
	int points;
	char display;
};

