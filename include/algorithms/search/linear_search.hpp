#ifndef LINEAR_SORT_HPP
#define LINEAR_SORT_HPP

#include <ranges>

template <typename T>
	requires std::ranges::range<T>
constexpr auto linear_search(const T& range, const std::ranges::range_value_t<T>& target) -> T::const_iterator {
	for (auto it = range.begin(); it != range.end(); ++it) {
		if (*it == target) return it;
	}
	return range.end();
}

#endif // !LINEAR_SORT_HPP
