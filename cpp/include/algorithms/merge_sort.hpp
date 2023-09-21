#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void mergeSort(std::vector<T> &vector) {
	if (vector.size() <= 1) return;

	auto mid = vector.begin() + vector.size() / 2;
	std::vector<T> left{vector.begin(), mid};
	std::vector<T> right{mid, vector.end()};

	mergeSort(left);
	mergeSort(right);

	std::vector<T> merged;
	int l{0};
	int r{0};

	while (l < left.size() && r < right.size()) {
		if (left[l] < right[r]) merged.push_back(left[l++]);
		else merged.push_back(right[r++]);
	}

	merged.insert(merged.end(), left.begin() + l, left.end());
	merged.insert(merged.end(), right.begin() + r, right.end());

	vector = std::move(merged);
}

#endif
