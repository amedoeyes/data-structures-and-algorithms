#include <cstdint>
#include <print>
#include <unordered_map>
#include <utility>
#include <vector>

import prim;

auto main() -> int {
	const auto graph = std::unordered_map<int32_t, std::vector<std::pair<int32_t, int32_t>>>{
		{0, {{1, 4}, {7, 8}}},
		{1, {{0, 4}, {2, 8}, {7, 11}}},
		{2, {{1, 8}, {3, 7}, {8, 2}, {5, 4}}},
		{3, {{2, 7}, {4, 9}, {5, 14}}},
		{4, {{3, 9}, {5, 10}}},
		{5, {{2, 4}, {3, 14}, {4, 10}, {6, 2}}},
		{6, {{5, 2}, {7, 1}, {8, 6}}},
		{7, {{0, 8}, {1, 11}, {6, 1}, {8, 7}}},
		{8, {{2, 2}, {6, 6}, {7, 7}}},
	};

	const auto source = 0;
	auto p = prim(graph, source);

	std::println("Parents:");
	for (const auto& [node, parent] : p) {
		std::println("Node {}: {}", node, parent);
	}
}
