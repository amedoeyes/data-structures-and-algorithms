#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <concepts>
#include <functional>
#include <ranges>

template <typename T, typename Compare = std::ranges::less>
	requires std::ranges::range<T>
				&& std::predicate<Compare, std::ranges::range_value_t<T>, std::ranges::range_value_t<T>>
constexpr auto selection_sort(T& range, Compare comp = Compare{}) -> void {
	for (auto it = range.begin(); it != range.end(); ++it) {
		auto min_it = it;
		for (auto it2 = it + 1; it2 != range.end(); ++it2) {
			if (comp(*it2, *min_it)) min_it = it2;
		}
		if (it != min_it) std::ranges::swap(*it, *min_it);
	}
}

#endif // !SELECTION_SORT_HPP
