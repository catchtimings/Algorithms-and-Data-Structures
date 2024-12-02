#include <iostream>
#include <ctime>
#include "task1.h"

int main() {
	try {
		srand(static_cast<int>(time(0)));
		//std::vector<int> vect = { 6, 59, 236, 0 }; //общий случай для проверок
		
		{
			std::vector <int> v(5);
			generate_vector(v);

			std::cout << "Before insert sort: ";
			print_vector(v);

			insert_sort(v);
			std::cout << "After insert sort: ";
			print_vector(v);
		}
		std::cout << '\n';
		{
			std::vector <int> v(10);
			generate_vector(v);

			std::cout << "Before comb sort: ";
			print_vector(v);

			insert_sort(v);
			std::cout << "After comb sort: ";
			print_vector(v);
		}
		std::cout << '\n';
		{
			std::vector <int> v(10);
			generate_vector(v);
			std::cout << "Before merge sort: ";
			print_vector(v);

			merge_sort(v);
			std::cout << "After merge sort: ";
			print_vector(v);
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}