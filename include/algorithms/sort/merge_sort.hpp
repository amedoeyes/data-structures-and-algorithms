#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <concepts>
#include <functional>
#include <iterator>
#include <ranges>
#include <vector>

template <typename T, typename Compare = std::ranges::less>
	requires std::ranges::range<T>
				&& std::predicate<Compare, std::ranges::range_value_t<T>, std::ranges::range_value_t<T>>
constexpr auto merge_sort(T& range, Compare comp = Compare{}) -> void {
	if (range.size() <= 1) return;
	auto mid_it = range.begin() + (range.size() / 2);
	auto left = std::vector(std::make_move_iterator(range.begin()), std::make_move_iterator(mid_it));
	auto right = std::vector(std::make_move_iterator(mid_it), std::make_move_iterator(range.end()));
	merge_sort(left, comp);
	merge_sort(right, comp);
	auto left_it = left.begin();
	auto right_it = right.begin();
	auto output_it = range.begin();
	while (left_it != left.end() && right_it != right.end()) {
		if (comp(*left_it, *right_it)) *output_it++ = std::move(*left_it++);
		else *output_it++ = std::move(*right_it++);
	}
	while (left_it != left.end()) *output_it++ = std::move(*left_it++);
	while (right_it != right.end()) *output_it++ = std::move(*right_it++);
}

#endif // !MERGE_SORT_HPP
