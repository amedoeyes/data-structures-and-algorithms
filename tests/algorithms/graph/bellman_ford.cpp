#include <cstdint>
#include <print>
#include <unordered_map>
#include <utility>
#include <vector>

import bellman_ford;

auto main() -> int {
	const auto graph = std::unordered_map<int32_t, std::vector<std::pair<int32_t, int32_t>>>{
		{0, {{1, 5}}},
		{1, {{2, 1}, {3, 2}}},
		{2, {{4, 1}}},
		{3, {}},
		{4, {{3, -1}}},
	};
	const auto cycle_graph = std::unordered_map<int32_t, std::vector<std::pair<int32_t, int32_t>>>{
		{0, {{1, 4}}},
		{1, {{2, -6}}},
		{2, {{3, 5}}},
		{3, {{1, -2}}},
	};

	const auto source = 0;
	auto result = bellman_ford(graph, source);

	if (!result.has_value()) {
		std::println("graph has negative cycle");
	} else {
		auto [d, p] = *result;

		std::println("Distances from node {}:", source);
		for (const auto& [node, distance] : d) {
			std::println("Node {}: {}", node, distance);
		}

		std::println("");

		std::println("Parents:");
		for (const auto& [node, parent] : p) {
			std::println("Node {}: {}", node, parent);
		}
	}
}
