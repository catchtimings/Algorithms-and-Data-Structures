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
	
	const int cnt = 1;

	std::ofstream file("C:/Users/ct/Documents/stats.csv");
	if (!file.is_open()) {
		throw std::logic_error("invalid file");
	}

	file << "size,ins_comp_random,ins_copy_random,combs_comp_random,combs_copy_random,merges_comp_random,merges_copy_random,ins_comp_sorted,ins_copy_sorted,combs_comp_sorted,combs_copy_sorted,merges_comp_sorted,merges_copy_sorted,ins_comp_reverse,ins_copy_reverse,combs_comp_reverse,combs_copy_reverse,merges_comp_reverse,merges_copy_reverse\n";
	for (size_t size : sizes) {
		stats insert_stats_total;
		stats comb_stats_total;
		stats merge_stats_total;
		for (size_t i = 0; i < cnt; ++i) {
			std::vector<int> random_vector(size);
			fill_vector(random_vector);
			std::vector<int> v1 = random_vector;
			std::vector<int> v2 = random_vector;
			std::vector<int> v3 = random_vector;
			stats random_stats1 = insert_sort(v1);
			stats random_stats2 = comb_sort(v2);
			stats random_stats3 = merge_sort(v3);
			insert_stats_total += random_stats1;
			comb_stats_total += random_stats2;
			merge_stats_total += random_stats3;
		}

		insert_stats_total /= cnt;
		comb_stats_total /= cnt;
		merge_stats_total /= cnt;

		std::vector<int> sorted_vector(size);
		generate_sorted_vector(sorted_vector);
		std::vector<int> ve1 = sorted_vector;
		std::vector<int> ve2 = sorted_vector;
		std::vector<int> ve3 = sorted_vector;
		stats sorted_stats1 = insert_sort(ve1);
		stats sorted_stats2 = comb_sort(ve2);
		stats sorted_stats3 = merge_sort(ve3);


		std::vector<int> reverse_sorted_vector(size);
		generate_reverse_sorted_array(reverse_sorted_vector);
		std::vector<int> vec1 = reverse_sorted_vector;
		std::vector<int> vec2 = reverse_sorted_vector;
		std::vector<int> vec3 = reverse_sorted_vector;
		stats reverse_stats1 = insert_sort(vec1);
		stats reverse_stats2 = comb_sort(vec2);
		stats reverse_stats3 = merge_sort(vec3);

		file << size << ","
			<< (insert_stats_total.comparison_count) << "," << (insert_stats_total.copy_count) << ","
			<< (comb_stats_total.comparison_count) << "," << (comb_stats_total.copy_count) << ","
			<< (merge_stats_total.comparison_count) << "," << (merge_stats_total.copy_count) << ","
			<< (sorted_stats1.comparison_count) << "," << (sorted_stats1.copy_count) << ","
			<< (sorted_stats2.comparison_count) << "," << (sorted_stats2.copy_count) << ","
			<< (sorted_stats3.comparison_count) << "," << (sorted_stats3.copy_count) << ","
			<< (reverse_stats1.comparison_count) << "," << (reverse_stats1.copy_count) << ","
			<< (reverse_stats2.comparison_count) << "," << (reverse_stats2.copy_count) << ","
			<< (reverse_stats2.comparison_count) << "," << (reverse_stats2.copy_count) << "\n";

		std::cout << "Middle stats for insert sort " << size << " random array: " << "\tComparison count: " << insert_stats_total.comparison_count << "\tCopy count: " << insert_stats_total.copy_count << "\n";
		std::cout << "Middle stats for comb sort " << size << " random array: " << "\tComparison count: " << comb_stats_total.comparison_count << "\tCopy count: " << comb_stats_total.copy_count << "\n";
		std::cout << "Middle stats for merge sort " << size << " random array: " << "\tComparison count: " << merge_stats_total.comparison_count << "\tCopy count: " << merge_stats_total.copy_count << "\n";

		std::cout << "\n\n";

		std::cout << "Stats for sorted " << size << " array (insert sort): " << "\tComparison count: " << sorted_stats1.comparison_count << "\tCopy count: " << sorted_stats1.copy_count << "\n";\
		std::cout << "Stats for sorted " << size << " array (comb sort): " << "\tComparison count: " << sorted_stats2.comparison_count << "\tCopy count: " << sorted_stats2.copy_count << "\n";
		std::cout << "Stats for sorted " << size << " array (merge sort): " << "\tComparison count: " << sorted_stats3.comparison_count << "\tCopy count: " << sorted_stats3.copy_count << "\n";

		std::cout << "\n\n";

		std::cout << "Stats for reverse " << size <<  " array(insert sort) : " << "\tComparison count : " << reverse_stats1.comparison_count << "\tCopy count : " << reverse_stats1.copy_count << "\n"; \
		std::cout << "Stats for reverse " << size <<  " array (comb sort): " << "\tComparison count: " << reverse_stats2.comparison_count << "\tCopy count: " << reverse_stats2.copy_count << "\n";
		std::cout << "Stats for reverse " << size << " array (merge sort): " << "\tComparison count: " << reverse_stats3.comparison_count << "\tCopy count: " << reverse_stats3.copy_count << "\n";

		std::cout << "----------------------------\n";
	}
	file.close();
	std::cout << "Processing is over";
}
