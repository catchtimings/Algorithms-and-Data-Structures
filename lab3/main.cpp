#include <iostream>
#include <ctime>
#include "task1.h"

int main() {
	try {
		srand(static_cast<int>(time(0)));
		//std::vector<int> v = { 6, 59, 236, 0 }; //общий случай для проверок
		
		{
			std::vector <int> v(5);
			generate_vector(v);
			std::cout << "Before sort: ";
			print_vector(v);

			insert_sort(v);
			std::cout << "After sort: ";
			print_vector(v);
		}
		std::cout << '\n';
		{

		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}