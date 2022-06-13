#include <iostream>
#include "World.h"

int main() {
	World test;
	int x;
	int y;
	test.printWorld();
	while (!test.isEmpty()) {
		//std::cin >> x;
		//std::cin >> y;
		x = rand() % 3;
		y = rand() % 3;
		test.executeField(x, y);
		test.printWorld();

	}
	return 1;
}