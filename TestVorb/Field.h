#pragma once

#include <iostream>

class IField
{
public:
	virtual bool execute() = 0;
	virtual void displayField() = 0;
	virtual int getPoints() = 0;
	virtual bool isPlain() = 0;
	~IField() {};
	
};

