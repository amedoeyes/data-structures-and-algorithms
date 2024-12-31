module;

#include <ranges>

export module linear_search;

export template <typename T>
	requires std::ranges::range<T>
constexpr auto linear_search(const T& range, const std::ranges::range_value_t<T>& target) -> T::const_iterator {
	for (auto it = range.begin(); it != range.end(); ++it) {
		if (*it == target) return it;
	}
	return range.end();
}
