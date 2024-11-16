#pragma once
#include <string>
#include <ctime>
#include "linkedlist.h"


std::string choose_names() {
	std::string names[] = { "Alexander", "Dmitriy", "Elizaveta", "Marina", "Semen", "Vadim", "Yulia" };
	size_t size = sizeof(names) / sizeof(names[0]);
	return names[rand() % size];
}

void generate_book(LinkedList<std::string>* book,
					const size_t& apps_count,
					const size_t& max_residents_count) {

	if (book->get_head() != nullptr)
		throw std::logic_error("Book must be empty");

	for (size_t i = 0; i < apps_count; ++i) {
		size_t residents_count = rand() % (max_residents_count);
		for (size_t j = 0; j < residents_count; ++j) {
			book[i].push_tail(choose_names());
		}
	}
}

void print_book(const LinkedList<std::string>* book) {
	size_t count = 1;
	for (Node<std::string>* ptr = book->get_head(); ptr != nullptr; ptr = ptr->next) {
		std::cout << "Appartment: " << count << "\tResident names: " << book[count] << std::endl;
		count++;
	}
}