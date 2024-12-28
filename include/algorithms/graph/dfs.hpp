#ifndef DFS_HPP
#define DFS_HPP

#include <concepts>
#include <ranges>
#include <set>
#include <stack>
#include <type_traits>

template <typename G, typename V, typename Visit>
	requires requires(const G& g, const V& v) {
		requires std::ranges::range<G>;
		{ g.at(v) } -> std::ranges::range;
		requires std::same_as<std::ranges::range_value_t<decltype(g.at(v))>, V>;
	} && requires {
		requires std::invocable<Visit, V>;
		requires std::same_as<std::invoke_result_t<Visit, V>, bool>;
	}
constexpr auto dfs(const G& graph, const V& source, Visit visit) -> void {
	auto visited = std::set<V>();
	auto stack = std::stack<V>();
	stack.emplace(source);
	while (!stack.empty()) {
		const auto u = stack.top();
		stack.pop();
		if (visited.contains(u)) continue;
		visited.emplace(u);
		if (!visit(u)) continue;
		for (const auto& v : graph.at(u)) {
			if (!visited.contains(v)) stack.emplace(v);
		}
	}
}

#endif // !DFS_HPP
