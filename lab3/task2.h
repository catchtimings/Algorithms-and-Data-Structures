#pragma once
#include <vector>
#include <fstream>
#include <ctime>
#include "sorts.h"
#include "stats.h"


void fill_vector(std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = rand() % 100 + 1;
	}
}


void generate_sorted_vector(std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = i + 1;
	}
}

void generate_reverse_sorted_array(std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = v.size() - i;
	}
}

void counter() {
	std::vector<size_t> sizes = { 1000, 2000, 3000, 4000, 5000, 10000, 25000, 50000, 100000 };
	

	std::ofstream file("stats.csv");
	if (!file.is_open()) {
		throw std::logic_error("invalid file");
	}

	file << "Size,Random_Comparisons,Random_Copies,Sorted_Comparisons,Sorted_Copies,Reverse_Comparisons,Reverse_Copies\n";

	for (size_t size : sizes) {
		stats random_stats_total;
		stats sorted_stats_total;
		stats reverse_stats_total;
		for (size_t i = 0; i < 10; ++i) {
			std::vector<int> random_vector(size);
			fill_vector(random_vector);
			stats random_stats1 = insert_sort(random_vector);
			stats random_stats2 = comb_sort(random_vector);
			stats random_stats3 = merge_sort(random_vector);
			random_stats_total += random_stats1 + random_stats2 + random_stats3;

			std::vector<int> sorted_vector(size);
			generate_sorted_vector(sorted_vector);
			stats sorted_stats1 = insert_sort(sorted_vector);
			stats sorted_stats2 = comb_sort(sorted_vector);
			stats sorted_stats3 = merge_sort(sorted_vector);
			sorted_stats_total += sorted_stats1 + sorted_stats2 + sorted_stats3;


			std::vector<int> reverse_sorted_vector(size);
			generate_reverse_sorted_array(reverse_sorted_vector);
			stats reverse_stats1 = insert_sort(reverse_sorted_vector);
			stats reverse_stats2 = comb_sort(reverse_sorted_vector);
			stats reverse_stats3 = merge_sort(reverse_sorted_vector);
			reverse_stats_total += reverse_stats1 + reverse_stats2 + reverse_stats3;

		}

		/*s1 = random_stats_total / 100;
		s2 = sorted_stats_total / 100;
		s3 = reverse_stats_total / 100;
		count = size;*/
		file << size << ","
			<< (random_stats_total.comparison_count / 100) << "," << (random_stats_total.copy_count / 100) << ","
			<< (sorted_stats_total.comparison_count / 100) << "," << (sorted_stats_total.copy_count / 100) << ","
			<< (reverse_stats_total.comparison_count / 100) << "," << (reverse_stats_total.copy_count / 100) << "\n";
		std::cout << "Middle stats for sorts " << size << ":" << "\nRandom:" << random_stats_total / 100 << "\nSorted stats:" << sorted_stats_total / 100 << "\nReverse stats: " << reverse_stats_total / 100 << '\n';
	}
	file.close();
	std::cout << "Processing is over";
}
