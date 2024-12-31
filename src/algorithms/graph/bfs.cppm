module;

#include <concepts>
#include <queue>
#include <ranges>
#include <set>
#include <type_traits>

export module bfs;

export template <typename G, typename V, typename Visit>
	requires requires(const G& g, const V& v) {
		requires std::ranges::range<G>;
		{ g.at(v) } -> std::ranges::range;
		requires std::same_as<std::ranges::range_value_t<decltype(g.at(v))>, V>;
	} && requires {
		requires std::invocable<Visit, V>;
		requires std::same_as<std::invoke_result_t<Visit, V>, bool>;
	}
auto bfs(const G& graph, const V& source, Visit visit) -> void {
	auto visited = std::set<V>();
	auto queue = std::queue<V>();
	queue.emplace(source);
	while (!queue.empty()) {
		const auto u = queue.front();
		queue.pop();
		if (visited.contains(u)) continue;
		visited.emplace(u);
		if (!visit(u)) continue;
		for (const auto& v : graph.at(u)) {
			if (!visited.contains(v)) queue.emplace(v);
		}
	}
}
