#include <iostream>
#include "linkedlist.h"

int main() {
	try {
		LinkedList<double> lst;
		lst.push_tail(1);
		lst.push_tail(6);
		lst.push_tail(90);
		lst.push_tail(19);
		
		LinkedList<double> lst2 = lst;
		std::cout << lst2;

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}