#include <iostream>
#include "functioins.h"

int main() {
	try {
		std::vector<int> v = { 957, 26, 9365, 837 };
		insert_sort(v);
		print_vector(v);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}