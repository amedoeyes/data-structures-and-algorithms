module;

#include <ranges>

export module binary_search;

export template <typename T>
	requires std::ranges::range<T>
constexpr auto binary_search(const T& range, const std::ranges::range_value_t<T>& target) -> T::const_iterator {
	auto left_it = range.begin();
	auto right_it = range.end();
	while (left_it <= right_it) {
		auto mid_it = left_it + ((right_it - left_it) / 2);
		if (*mid_it == target) return mid_it;
		if (target > *mid_it) left_it = mid_it + 1;
		else right_it = mid_it - 1;
	}
	return range.end();
}
