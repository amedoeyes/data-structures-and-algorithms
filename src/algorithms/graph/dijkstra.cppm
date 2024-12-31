module;

#include <concepts>
#include <functional>
#include <queue>
#include <ranges>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

export module dijkstra;

export template <typename G, typename V>
	requires requires(const G& g, const V& v) {
		requires std::ranges::range<G>;
		{ g.at(v) } -> std::ranges::range;
		requires std::integral<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>
							 || std::floating_point<typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>;
		requires std::same_as<
			std::ranges::range_value_t<decltype(g.at(v))>,
			std::pair<V, typename std::ranges::range_value_t<decltype(g.at(v))>::second_type>>;
	}
constexpr auto dijkstra(const G& graph, const V& source) -> std::tuple<
	std::unordered_map<V, typename std::ranges::range_value_t<decltype(graph.at(source))>::second_type>,
	std::unordered_map<V, V>> {
	using weight_type =
		typename std::ranges::range_value_t<typename std::ranges::range_value_t<G>::second_type>::second_type;
	auto dist = std::unordered_map<V, weight_type>();
	auto parent = std::unordered_map<V, V>();
	auto visited = std::set<V>();
	auto pq = std::priority_queue<std::pair<weight_type, V>, std::vector<std::pair<weight_type, V>>, std::greater<>>();
	dist[source] = weight_type{};
	parent[source] = source;
	pq.emplace(weight_type{}, source);
	while (!pq.empty()) {
		const auto [d, u] = pq.top();
		pq.pop();
		if (visited.contains(u) || (dist.contains(u) && dist[u] > d)) continue;
		visited.emplace(u);
		for (const auto& [v, w] : graph.at(u)) {
			if (!visited.contains(v) && (!dist.contains(v) || d + w < dist[v])) {
				dist[v] = d + w;
				parent[v] = u;
				pq.emplace(d + w, v);
			}
		}
	}
	return {dist, parent};
}
