#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

void generate_vector(std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = rand() % 100 + 1;
	}
}

void print_vector(const std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << '\n';
}

void insert_sort(std::vector<int>& v) {
	if (v.size() == 0) return;

	for (size_t i = 1; i < v.size(); ++i) {
		int key = v[i];
		size_t j = i;
		while (j > 0 && v[j-1] > key) {
			std::swap(v[j], v[j - 1]);
			--j;
		}
		v[j] = key; 
	}
}

void comb_sort(std::vector<int>& v) {
	if (v.size() == 0) return;

	//const double factor = 1.247;
	double step = v.size() - 1;

	while (step >= 1) {
		for (size_t i = 0; i + step < v.size(); ++i) {
			if (v[i] > v[i + step]) {
				std::swap(v[i], v[i + step]);
			}
		}
		step--;
	}
}