#include <iostream>
#include <ctime>
#include "functioins.h"

int main() {
	try {
		srand(static_cast<int>(time(0)));
		std::vector <int> v(10);
		generate_vector(v);
		std::cout << "Before sort: ";
		print_vector(v);

		insert_sort(v);
		std::cout << "After sort: ";
		print_vector(v);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}