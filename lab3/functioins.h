#pragma once
#include <vector>
#include <stdexcept>

void generate_vector(std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = rand() % 10000 + 1;
	}
}

void print_vector(const std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << '\n';
}

void insert_sort(std::vector<int>& v) {
	if (v.size() == 0) throw std::logic_error("Vector is empty");

	for (size_t i = 1; i < v.size(); ++i) {
		int key = v[i];
		size_t j = i;
		while (j > 0 && v[j-1] > key) {
			v[j] = v[j-1];
			--j;
		}
		v[j] = key; 
	}
}