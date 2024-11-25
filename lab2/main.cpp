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
			lst2.push_tail(11);
			lst2.push_tail(12);
			lst2.push_tail(13);

			std::cout << "List2: " << lst2 << std::endl;


			lst.push_tail(lst2);
			std::cout << "List: " << lst << std::endl;


			/*lst.push_head(52);
			std::cout << "List: " << lst << std::endl;

			lst.pop_tail();
			std::cout << "List: " << lst << std::endl;
			
			lst.delete_node(2);
			std::cout << "List: " << lst << std::endl;

			lst[2]->data = 99;
			std::cout << "List: " << lst << std::endl;*/

		}

		/*{
			srand(static_cast<size_t>(time(0)));
			const size_t MAX_APPS = 100;
			const size_t MAX_RESIDENTS = 7;

			LinkedList<std::string>* book = generate_book(MAX_APPS, MAX_RESIDENTS);

			print_book(book, MAX_APPS);

			delete[] book;
		}*/
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}