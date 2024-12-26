#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <concepts>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

template <typename T, typename Compare = std::ranges::less>
	requires std::ranges::range<T>
				&& std::predicate<Compare, std::ranges::range_value_t<T>, std::ranges::range_value_t<T>>
constexpr auto merge_sort(T& range, Compare comp = Compare{}) -> void {
	const auto begin = std::ranges::begin(range);
	const auto end = std::ranges::end(range);
	const auto dist = std::ranges::distance(begin, end);
	if (dist <= 1) return;
	auto mid = begin + (dist / 2);
	auto left = std::vector(std::make_move_iterator(begin), std::make_move_iterator(mid));
	auto right = std::vector(std::make_move_iterator(mid), std::make_move_iterator(end));
	merge_sort(left, comp);
	merge_sort(right, comp);
	auto left_it = left.begin();
	auto right_it = right.begin();
	auto output_it = begin;
	while (left_it != left.end() && right_it != right.end()) {
		if (comp(*left_it, *right_it)) *output_it++ = std::move(*left_it++);
		else *output_it++ = std::move(*right_it++);
	}
	while (left_it != left.end()) *output_it++ = std::move(*left_it++);
	while (right_it != right.end()) *output_it++ = std::move(*right_it++);
}

#endif // !MERGE_SORT_HPP
