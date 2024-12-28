#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <concepts>
#include <functional>
#include <ranges>

template <typename T, typename Compare = std::ranges::less>
	requires std::ranges::range<T>
				&& std::predicate<Compare, std::ranges::range_value_t<T>, std::ranges::range_value_t<T>>
constexpr auto insertion_sort(T& range, Compare comp = Compare{}) -> void {
	for (auto it = range.begin() + 1; it != range.end(); ++it) {
		auto temp = std::move(*it);
		auto it2 = it;
		while (it2 > range.begin() && !comp(*(it2 - 1), temp)) {
			*it2 = std::move(*(it2 - 1));
			--it2;
		}
		*it2 = std::move(temp);
	}
}

#endif // !INSERTION_SORT_HPP
