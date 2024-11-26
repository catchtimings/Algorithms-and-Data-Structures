#include <iostream>
#include "linkedlist.h"
#include "function.h"

int main() {
	try {
		{
			LinkedList<double> lst;
			lst.push_tail(1);
			lst.push_tail(2);
			lst.push_tail(3);
			lst.push_tail(4);
			std::cout << "List: " << lst << std::endl;
			
			LinkedList<double> lst2;
			lst2.push_tail(10);
			lst2.push_tail(12);
			lst2.push_tail(13);
			lst2.push_tail(14);
			lst2.push_tail(15);
			std::cout << "List2: " << lst2 << std::endl;

			lst.push_head(lst2);
			std::cout << "Push head list: " << lst << std::endl;

		}
		std::cout << std::endl;
		{
			LinkedList<double> lst;
			lst.push_tail(1);
			lst.push_tail(2);
			lst.push_tail(3);
			lst.push_tail(4);
			std::cout << "List: " << lst << std::endl;

			LinkedList<double> lst2;
			lst2.push_tail(10);
			lst2.push_tail(12);
			lst2.push_tail(13);
			lst2.push_tail(14);
			lst2.push_tail(15);
			std::cout << "List2: " << lst2 << std::endl;

			lst.push_tail(lst2);
			std::cout << "Push tail list: " << lst << std::endl;

		}
		std::cout << std::endl;
		{
			srand(static_cast<size_t>(time(0)));
			const size_t MAX_APPS = 50;
			const size_t MAX_RESIDENTS = 4;

			LinkedList<std::string>* book = generate_book(MAX_APPS, MAX_RESIDENTS);

			print_book(book, MAX_APPS);

			delete[] book;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}