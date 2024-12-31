#include <array>
#include <print>

import bubble_sort;

auto main() -> int {
	auto array = std::array{4, 2, 1, 7, 6};

	std::print("original: ");
	for (auto i : array) {
		std::print("{} ", i);
	}
	std::println("");

	bubble_sort(array);

	std::print("sorted: ");
	for (auto i : array) {
		std::print("{} ", i);
	}
	std::println("");
}
