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
		--step;
	}
}

void merge(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& v) {
	size_t i = 0, j = 0, k = 0;

	while (i < v1.size() && j < v2.size()) {
		if (v1[i] <= v2[j]) {
			v[k++] = v1[i++];
		}
		else {
			v[k++] = v2[j++];
		}
	}

	while (i < v1.size()) {
		v[k++] = v1[i++];
	}
	while (j < v2.size()) {
		v[k++] = v2[j++];
	}
}

void merge_sort(std::vector<int>& v) {
	if (v.size() <= 1) return;

	size_t middle = v.size() / 2;
	std::vector<int>v1(v.begin(), v.begin() + middle);
	std::vector<int>v2(v.begin() + middle, v.end());

	merge_sort(v1);
	merge_sort(v2);

	merge(v1, v2, v);
}