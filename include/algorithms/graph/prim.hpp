#ifndef PRIM_HPP
#define PRIM_HPP

#include <concepts>
#include <functional>
#include <queue>
#include <ranges>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename G, typename V>
	requires requires(const G& g, const V& v) {
		requires std::ranges::range<G>;
		{ g.at(v) } -> std::ranges::range;
		requires std::integral<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>
							 || std::floating_point<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>;
		requires std::same_as<
			std::ranges::range_value_t<decltype(g.at(v))>,
			std::pair<V, typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>>;
	}
constexpr auto prim(const G& graph, const V& source) -> std::unordered_map<V, V> {
	using weight_type =
		typename std::ranges::range_value_t<typename std::ranges::range_value_t<G>::second_type>::second_type;
	auto parent = std::unordered_map<V, V>();
	auto visited = std::set<V>();
	auto pq =
		std::priority_queue<std::tuple<weight_type, V, V>, std::vector<std::tuple<weight_type, V, V>>, std::greater<>>();
	parent[source] = source;
	visited.emplace(source);
	for (const auto& [v, w] : graph.at(source)) pq.emplace(w, source, v);
	while (!pq.empty()) {
		const auto [_, u, v] = pq.top();
		pq.pop();
		if (visited.contains(v)) continue;
		visited.emplace(v);
		parent[v] = u;
		for (const auto& [v2, w] : graph.at(v)) pq.emplace(w, v, v2);
	}
	return parent;
}

#endif // !PRIM_HPP
