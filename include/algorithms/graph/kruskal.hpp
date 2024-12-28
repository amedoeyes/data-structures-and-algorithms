#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "data_structures/union_find.hpp"

#include <concepts>
#include <functional>
#include <queue>
#include <ranges>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename G>
	requires requires { typename G::key_type; } && requires(const G& g, G::key_type v) {
		requires std::ranges::range<G>;
		{ g.at(v) } -> std::ranges::range;
		requires std::integral<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>
							 || std::floating_point<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>;
		requires std::same_as<
			std::ranges::range_value_t<decltype(g.at(v))>,
			std::pair<decltype(v), typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>>;
	}
constexpr auto kruskal(const G& graph) -> std::unordered_map<typename G::key_type, typename G::key_type> {
	using vertex_type = G::key_type;
	using weight_type = std::ranges::range_value_t<typename std::ranges::range_value_t<G>::second_type>::second_type;
	auto parent = std::unordered_map<vertex_type, vertex_type>();
	auto pq = std::priority_queue<
		std::tuple<weight_type, vertex_type, vertex_type>,
		std::vector<std::tuple<weight_type, vertex_type, vertex_type>>,
		std::greater<>>();
	for (const auto& [u, edges] : graph) {
		for (const auto& [v, w] : edges) pq.emplace(w, u, v);
	}
	auto uf = union_find(graph | std::views::keys | std::ranges::to<std::vector>());
	while (!pq.empty()) {
		const auto [w, u, v] = pq.top();
		pq.pop();
		if (uf.find(u) != uf.find(v)) {
			parent[v] = u;
			uf.unite(u, v);
		}
	}
	return parent;
}

#endif // !KRUSKAL_HPP
