#include <iostream>
#include "polynom.h"

int main() {
	Polynom<int> new_polynom(4);

	std::cout << new_polynom;

	return 0;
}