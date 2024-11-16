#include <iostream>
#include "linkedlist.h"
#include "function.h"



int main() {
	try {
		/*LinkedList<double> lst;
		lst.push_tail(1);
		lst.push_tail(6);
		lst.push_tail(90);
		lst.push_tail(19);
		
		LinkedList<double> lst2 = lst;
		std::cout << lst2;*/

		srand(static_cast<size_t>(time(0)));
		const size_t MAX_APPS = 100;
		const size_t MAX_RESIDENTS = 10;

		LinkedList<std::string> book[MAX_APPS];
		generate_book(book, MAX_APPS, MAX_RESIDENTS);

		print_book(book);

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}