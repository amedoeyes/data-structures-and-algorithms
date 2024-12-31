module;

#include <concepts>
#include <optional>
#include <ranges>
#include <tuple>
#include <unordered_map>
#include <utility>

export module bellman_ford;

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
constexpr auto bellman_ford(const G& graph, const V& source) -> std::optional<std::tuple<
	std::unordered_map<V, typename std::ranges::range_value_t<decltype(graph.at(source))>::second_type>,
	std::unordered_map<V, V>>> {
	using weight_type =
		typename std::ranges::range_value_t<typename std::ranges::range_value_t<G>::second_type>::second_type;
	auto dist = std::unordered_map<V, weight_type>();
	auto parent = std::unordered_map<V, V>();
	dist[source] = weight_type{};
	parent[source] = source;
	for (auto _ : std::views::iota(0ul, graph.size() - 1)) {
		for (const auto& [u, edges] : graph) {
			if (!dist.contains(u)) continue;
			const auto d = dist[u];
			for (const auto& [v, w] : edges) {
				if (!dist.contains(v) || d + w < dist[v]) {
					dist[v] = d + w;
					parent[v] = u;
				}
			}
		}
	}
	for (const auto& [u, edges] : graph) {
		if (!dist.contains(u)) continue;
		const auto d = dist[u];
		for (const auto& [v, w] : edges) {
			if (d + w < dist[v]) return std::nullopt;
		}
	}
	return std::tuple{dist, parent};
}
