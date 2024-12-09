#pragma once
#include <vector>
#include <stdexcept>
#include "stats.h"


void print_vector(const std::vector<int>& v) {
	for (int num : v) {
		std::cout << num << " ";
	}
	std::cout << '\n';
}

stats insert_sort(std::vector<int>& v) {
	stats s;
	if (v.size() == 0) return s;

	
	for (size_t i = 1; i < v.size(); ++i) {
		int key = v[i];
		size_t j = i;
		while (j > 0 && v[j-1] > key) {
			std::swap(v[j], v[j - 1]);
			--j;
			s.comparison_count++;
			s.copy_count += 3;
		}
		v[j] = key; 
	}

	return s;
}

stats comb_sort(std::vector<int>& v) {
	stats s;
	if (v.size() == 0) return s;

	const double k = 1.247;
	double step = static_cast<double>(v.size());
	bool swapped = false;

	while (step > 1 || swapped) {
		if (step > 1) step = std::floor(step / k);
		swapped = false;

		for (size_t i = 0; i + step < v.size(); ++i) {
			if (v[i] > v[i + step]) {
				std::swap(v[i], v[i + step]);
				swapped = true;
				++s.comparison_count;
				s.copy_count += 3;
			}
		}
	}
	return s;
}

void merge(const std::vector<int>& v1, const std::vector<int>& v2, 
	std::vector<int>& v, stats& s) {
	size_t i = 0, j = 0, k = 0;

	while (i < v1.size() && j < v2.size()) {
		s.comparison_count++;
		if (v1[i] <= v2[j]) {
			v[k++] = v1[i++];
		}
		else {
			v[k++] = v2[j++];
		}
		s.copy_count++;
	}

	while (i < v1.size()) {
		v[k++] = v1[i++];
		s.copy_count++;
	}
	while (j < v2.size()) {
		v[k++] = v2[j++];
		s.copy_count++;
	}
}

stats merge_sort(std::vector<int>& v) {
	stats s;
	if (v.size() <= 1) return s;

	size_t middle = v.size() / 2;
	std::vector<int>v1(v.begin(), v.begin() + middle);
	std::vector<int>v2(v.begin() + middle, v.end());

	stats s1 = merge_sort(v1);
	stats s2 = merge_sort(v2);

	s = s1 + s2;

	merge(v1, v2, v, s);

	return s;
}