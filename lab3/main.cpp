#include <ctime>
#include "sorts.h"
#include "task2.h"

int main() {
	try {
		srand(static_cast<int>(time(0)));
		//std::vector<int> v = { 6, 59, 236, 0 }; //общий случай для проверок
		std::vector <int> v(10);
		fill_vector(v);
		srand(static_cast<int>(time(0)));
		//Сортировка вставками
		{
			std::vector <int> v1 = v;

			std::cout << "Before insert sort: ";
			print_vector(v1);

			stats s = insert_sort(v1);
			std::cout << "After insert sort: ";
			print_vector(v1);

			std::cout << s;
		}
		std::cout << '\n';
		//Сортировка расчёской
		{
			std::vector <int> v2 = v;

			std::cout << "Before comb sort: ";
			print_vector(v2);

			stats s = comb_sort(v2);
			std::cout << "After comb sort: ";
			print_vector(v2);
			std::cout << s;
		}
		std::cout << '\n';
		//Сортировка слиянием
		{
			std::vector <int> v3 = v;

			std::cout << "Before merge sort: ";
			print_vector(v3);

			stats s = merge_sort(v3);
			std::cout << "After merge sort: ";
			print_vector(v3);
			std::cout << s;
		}
		std::cout << '\n';
		//Подсчёт для больших массивов
		{
			std::cout << "--------------------------\n";
			counter();

		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}