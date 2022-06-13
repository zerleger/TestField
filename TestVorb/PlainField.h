#pragma once
#include "Field.h"

class PlainField : public IField
{
public:
	PlainField();
	bool execute() override;
	void displayField() override;
	int getPoints() override;
	bool isPlain() override;
private:
	int points;
	char display;

};

