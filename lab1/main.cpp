#include <iostream>
#include "polynom.h"
#include "function.h"

int main() {
	int array[] = { 1,2,3,4 };

	Polynom<int> new_polynom(array, 3);

	std::cout << new_polynom;
	std::cout << "Roots: " << *find_real_roots(new_polynom);

	return 0;
}