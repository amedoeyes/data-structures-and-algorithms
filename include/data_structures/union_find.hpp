#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <cstdint>
#include <functional>
#include <unordered_map>
#include <vector>

template <typename T, typename Hash = std::hash<T>>
class union_find {
public:
	explicit union_find(const std::vector<T>& vertices) {
		for (const auto& v : vertices) {
			parent_[v] = v;
			rank_[v] = 0;
		}
	}

	auto find(T v) -> T {
		if (parent_[v] != v) {
			parent_[v] = find(parent_[v]);
		}
		return parent_[v];
	}

	void unite(T u, T v) {
		T root_u = find(u);
		T root_v = find(v);
		if (root_u != root_v) {
			if (rank_[root_u] > rank_[root_v]) {
				parent_[root_v] = root_u;
			} else if (rank_[root_u] < rank_[root_v]) {
				parent_[root_u] = root_v;
			} else {
				parent_[root_v] = root_u;
				rank_[root_u]++;
			}
		}
	}

private:
	std::unordered_map<T, T, Hash> parent_;
	std::unordered_map<T, int32_t, Hash> rank_;
};

#endif // !UNION_FIND_HPP
