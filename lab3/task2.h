#pragma once
#include <vector>
#include <ctime>
#include "sorts.h"
#include "stats.h"


size_t choose_count() {
	const size_t ARRAY[] = { 1000, 2000, 3000, 4000, 5000, 10000, 25000, 50000, 100000 };
	size_t cap = sizeof(ARRAY) / sizeof(ARRAY[0]);
	return ARRAY[rand() % cap];
}

void counter(stats& s1, stats& s2, stats& s3, size_t& count) {
	size_t size = choose_count();
	std::vector<int>v(size);
	fill_vector(v);

	std::vector<int>v1 = v;
	std::vector<int>v2 = v;
	std::vector<int>v3 = v;

	s1 = insert_sort(v1);
	s2 = comb_sort(v2);
	s3 = merge_sort(v3);
	count = size;
}
