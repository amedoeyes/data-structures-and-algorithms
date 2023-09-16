#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <functional>
#include <memory>
template <typename T>
class Node {
	public:
	T data;
	std::shared_ptr<Node<T>> next;
	std::shared_ptr<Node<T>> prev;
	Node(T data);
};

template <typename T>
class LinkedList {
	public:
	LinkedList();

	auto getFirst() -> T;
	auto getLast() -> T;
	auto get(const int &index) -> T;
	auto getSize() -> int;

	auto insertFirst(const T &data) -> void;
	auto insertLast(const T &data) -> void;
	auto insert(const T &data, const int &index) -> void;

	auto updateFirst(const T &data) -> void;
	auto updateLast(const T &data) -> void;
	auto update(const int &index, const T &data) -> void;

	auto removeFirst() -> void;
	auto removeLast() -> void;
	auto remove(const int &index) -> void;

	auto reverse() -> void;
	auto traverse(const std::function<void(T)> &visit) -> void;

	auto isEmpty() -> bool;
	auto clear() -> void;

	class Iterator {
		public:
		Iterator(std::shared_ptr<Node<T>> node);

		auto operator*() -> T;
		auto operator++() -> Iterator &;
		auto operator==(const Iterator &other) -> bool;
		auto operator!=(const Iterator &other) -> bool;

		private:
		std::shared_ptr<Node<T>> node;
	};

	auto begin() -> Iterator;
	auto end() -> Iterator;

	private:
	std::shared_ptr<Node<T>> head;
	std::shared_ptr<Node<T>> tail;
	int size;

	auto getNode(const int &index) -> std::shared_ptr<Node<T>>;
};

#endif
