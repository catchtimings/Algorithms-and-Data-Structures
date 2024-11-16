#include <iostream>
#include "linkedlist.h"

int main() {
	try {
		LinkedList lst;
		lst.push_tail(1);
		lst.push_tail(6);
		lst.push_tail(90);
		lst.push_tail(19);

		for (Node* ptr = lst.head(); ptr != nullptr; ptr = ptr->next) {
			std::cout << lst->data << " ";
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}