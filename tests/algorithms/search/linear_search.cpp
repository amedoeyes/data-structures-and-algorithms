#include "algorithms/search/linear_search.hpp"

#include <array>
#include <print>

auto main() -> int {
	auto array = std::array{4, 2, 1, 7, 6};

	const auto* it = linear_search(array, 2);

	if (it != array.end()) std::println("found");
	else std::println("not found");
}
