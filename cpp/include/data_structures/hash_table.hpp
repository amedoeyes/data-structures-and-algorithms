#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <memory>
#include <stdexcept>

#include "data_structures/linked_list.hpp"

template <typename K, typename V>
class HashTable {
	private:
	class Node {
		public:
		Node(const K key, const V value) : key{key}, value{value} {}

		K key;
		V value;
	};

	using NodePtr = std::shared_ptr<Node>;
	using DataPtr = std::unique_ptr<LinkedList<NodePtr>[]>;

	public:
	HashTable()
		: size_{0},
		  capacity_{10},
		  data_{std::make_unique<LinkedList<NodePtr>[]>(capacity_)} {}

	auto operator[](const K &key) -> V & {
		size_t i{hash(key)};

		for (const NodePtr &node : data_[i]) {
			if (node->key == key) return node->value;
		}

		NodePtr newNode{std::make_shared<Node>(key, V{})};

		data_[i].pushBack(newNode);
		++size_;

		return newNode->value;
	}

	auto operator[](const K &key) const -> const V & {
		return get(key);
	}

	auto set(const K &key, const V &value) -> void {
		if (size_ == capacity_) resize();

		size_t i{hash(key)};

		for (const NodePtr &node : data_[i]) {
			if (node->key == key) {
				node->value = value;
				return;
			}
		}

		NodePtr newNode{std::make_shared<Node>(key, value)};

		data_[i].pushBack(newNode);
		++size_;
	}

	auto get(const K &key) -> V & {
		size_t i{hash(key)};

		for (const NodePtr &node : data_[i]) {
			if (node->key == key) return node->value;
		}

		throw std::out_of_range("Key not found: " + key);
	}

	auto clear() -> void {
		for (size_t i{0}; i < capacity_; ++i) {
			data_[i].clear();
		}
	}

	private:
	size_t size_;
	size_t capacity_;
	DataPtr data_;

	auto hash(const K &key) const -> size_t {
		std::hash<K> hasher{};

		return hasher(key) % capacity_;
	}

	auto resize() -> void {
		size_t oldCapacity{capacity_};
		capacity_ *= 2;
		DataPtr newData{std::make_unique<LinkedList<NodePtr>[]>(capacity_)};

		for (size_t i{0}; i < oldCapacity; ++i) {
			for (const NodePtr &node : data_[i]) {
				size_t index{hash(node->key)};
				newData[index].pushBack(node);
			}
		}

		data_ = std::move(newData);
	}
};

#endif
