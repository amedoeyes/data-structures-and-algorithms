#include <print>
#include <unordered_map>
#include <vector>

import dfs;

auto main() -> int {
	const auto graph = std::unordered_map<int, std::vector<int>>{
		{1, {2, 3}},
		{2, {4, 5}},
		{3, {6}},
		{4, {}},
		{5, {6}},
		{6, {}},
	};
	dfs(graph, 1, [](auto v) {
		std::println("{}", v);
		return true;
	});
}
