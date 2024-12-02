#include <iostream>
#include <ctime>
#include "task1.h"
#include "task2.h"

int main() {
	try {
		srand(static_cast<int>(time(0)));
		//std::vector<int> vect = { 6, 59, 236, 0 }; //общий случай для проверок
		
		//Сортировка вставками
		{
			std::vector <int> v(10);
			generate_vector(v);

			std::cout << "Before insert sort: ";
			print_vector(v);

			stats s = insert_sort(v);
			std::cout << "After insert sort: ";
			print_vector(v);

			std::cout << s;
		}
		std::cout << '\n';
		//Сортировка расчёской
		{
			std::vector <int> v(10);
			generate_vector(v);

			std::cout << "Before comb sort: ";
			print_vector(v);

			stats s = comb_sort(v);
			std::cout << "After comb sort: ";
			print_vector(v);
			std::cout << s;
		}
		std::cout << '\n';
		//Сортировка слиянием
		{
			std::vector <int> v(10);
			generate_vector(v);

			std::cout << "Before merge sort: ";
			print_vector(v);

			stats s = merge_sort(v);
			std::cout << "After merge sort: ";
			print_vector(v);
			std::cout << s;
		}
		std::cout << '\n';
		//Подсчёт для больших массивов
		{
			stats insert_stats;
			stats comb_stats;
			stats merge_stats;
			size_t count = 0;
			counter(insert_stats, comb_stats, merge_stats, count);
			std::cout << "Stats for vector with " << count << " elements: " << "\nInsert stats:  " << insert_stats << "\nComb stats:  " << comb_stats << "\nMerge stats:  " << merge_stats;

		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}