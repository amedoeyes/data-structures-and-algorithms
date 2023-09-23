#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

template <typename T>
auto insertionSort(std::vector<T> &vector) -> void {
	for (size_t i{1}; i < vector.size(); i++) {
		T key = vector[i];
		size_t j{i};

		while (j > 0 && vector[j - 1] > key) {
			vector[j] = vector[j - 1];
			j--;
		}

		vector[j] = key;
	}
}

#endif
