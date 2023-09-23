#ifndef QUIK_SORT_HPP
#define QUIK_SORT_HPP

#include <type_traits>
#include <vector>

template <typename T>
void quickSort(std::vector<T>& vector, size_t left, size_t right) {
	if (left >= right) return;

	T pivot = vector[right];
	size_t i = left;

	for (size_t j = left; j < right; ++j) {
		if (vector[j] <= pivot) std::swap(vector[i++], vector[j]);
	}

	std::swap(vector[i], vector[right]);

	quickSort(vector, left, i == 0 ? 0 : i - 1);
	quickSort(vector, i, right);
};

template <typename T>
void quickSort(std::vector<T>& vector) {
	quickSort(vector, 0, vector.size() - 1);
}

#endif
