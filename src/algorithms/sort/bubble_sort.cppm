module;

#include <concepts>
#include <functional>
#include <ranges>

export module bubble_sort;

export template <typename T, typename Compare = std::ranges::less>
	requires std::ranges::range<T>
				&& std::predicate<Compare, std::ranges::range_value_t<T>, std::ranges::range_value_t<T>>
constexpr auto bubble_sort(T& range, Compare comp = Compare{}) -> void {
	auto swapped = true;
	auto size = range.size() - 1;
	while (swapped) {
		swapped = false;
		for (auto it = range.begin() + 1; it != range.end(); ++it) {
			if (!comp(*(it - 1), *it)) {
				std::ranges::swap(*(it - 1), *it);
				swapped = true;
			}
		}
		--size;
	}
}
