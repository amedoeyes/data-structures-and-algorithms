module;

#include <cstdint>
#include <functional>
#include <unordered_map>
#include <vector>

export module disjoint_set;

export template <typename T, typename Hash = std::hash<T>>
class disjoint_set {
public:
	explicit disjoint_set(const std::vector<T>& vertices) {
		for (const auto& v : vertices) {
			parent_[v] = v;
			rank_[v] = 0;
		}
	}

	auto find(const T& v) -> T {
		if (parent_[v] != v) {
			parent_[v] = find(parent_[v]);
		}
		return parent_[v];
	}

	auto unite(const T& u, const T& v) -> void {
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

	auto connected(const T& u, const T& v) -> bool {
		return find(u) == find(v);
	}

private:
	std::unordered_map<T, T, Hash> parent_;
	std::unordered_map<T, int32_t, Hash> rank_;
};
