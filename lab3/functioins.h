#pragma once
#include <vector>
#include <stdexcept>

void print_vector(const std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << '\n';
}

void insert_sort(std::vector<int>& v) {
	if (v.size() == 0) throw std::logic_error("Vector is empty");

	for (size_t i = 0; i < v.size() - 1; ++i) {
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (v[i] > v[j]) {
				std::swap(v[j-1], v[j]);
			}
		}
	}
}