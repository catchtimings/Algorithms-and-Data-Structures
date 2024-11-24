#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "linkedlist.h"


std::string choose_names() {
	std::string names[] = { "Alexander", "Dmitriy", "Elizaveta", "Marina", "Semen", "Vadim", "Yulia" };
	size_t size = sizeof(names) / sizeof(names[0]);
	return names[rand() % size];
}

LinkedList<std::string>* generate_book(const size_t& apps_count,
									const size_t& max_residents_count) {

	LinkedList<std::string>* book = new LinkedList<std::string>[apps_count];

	for (size_t i = 0; i < apps_count; ++i) {
		size_t residents_count = (rand() % max_residents_count) + 1;
		for (size_t j = 0; j < residents_count; ++j) {
			book[i].push_tail(choose_names());
		}
	}
	return book;
}

void print_book(const LinkedList<std::string>* book, const size_t& apps_count) {
	for (size_t i = 0; i < apps_count; ++i) {
		std::cout << "Appartment: " << i + 1 << "\t\tNames: " << book[i] << std::endl;
	}
}