#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>

template <typename T>
class LinkedList {
	class Node {
		public:
		Node(T data) : data{data}, next{nullptr}, prev{nullptr} {};

		T data;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
	};

	public:
	LinkedList() : head_{nullptr}, tail_{nullptr}, size_{0} {};

	auto front() -> T {
		return head_->data;
	};

	auto back() -> T {
		return tail_->data;
	};

	auto get(const int &index) -> T {
		return getNode(index)->data;
	};

	auto size() -> const int {
		return size_;
	};

	auto insertFront(const T &data) -> void {
		insertNodeAtHead(std::make_shared<Node>(data));
	};

	auto insertBack(const T &data) -> void {
		insertNodeAtTail(std::make_shared<Node>(data));
	};

	auto insertAfter(const T &data, const int &index) -> void {
		std::shared_ptr<Node> newNode{std::make_shared<Node>(data)};

		if (index == 0) return insertNodeAfter(head_, newNode);
		if (index == size_ - 1) return insertNodeAfter(tail_, newNode);

		insertNodeAfter(getNode(index), newNode);
	};

	auto insertBefore(const T &data, const int &index) -> void {
		std::shared_ptr<Node> newNode{std::make_shared<Node>(data)};

		if (index == 0) return insertNodeBefore(head_, newNode);
		if (index == size_ - 1) return insertNodeBefore(tail_, newNode);

		insertNodeBefore(getNode(index), newNode);
	}

	auto updateFront(const T &data) -> void {
		head_->data = data;
	};

	auto updateBack(const T &data) -> void {
		tail_->data = data;
	};

	auto update(const int &index, const T &data) -> void {
		if (index == 0) return updateFront(data);
		if (index == size_ - 1) return updateBack(data);

		getNode(index)->data = data;
	};

	auto removeFront() -> void {
		removeNode(head_);
	};

	auto removeBack() -> void {
		removeNode(tail_);
	};

	auto remove(const int &index) -> void {
		if (index == 0) return removeFront();
		if (index == size_ - 1) return removeBack();

		removeNode(getNode(index));
	};

	auto reverse() -> void {
		std::shared_ptr<Node> temp{head_};

		head_ = tail_;
		tail_ = temp;

		while (temp) {
			std::swap(temp->prev, temp->next);
			temp = temp->prev;
		}
	};

	auto traverse(const std::function<void(T)> &visit) -> void {
		for (const T &it : *this) {
			visit(it);
		}
	};

	auto isEmpty() -> bool {
		return size_ == 0;
	};

	auto clear() -> void {
		while (head_) {
			head_->prev = nullptr;
			head_ = head_->next;
		}

		tail_ = nullptr;
		size_ = 0;
	};

	class Iterator {
		public:
		Iterator(std::shared_ptr<Node> node) : node{node} {};

		auto operator*() -> T {
			return node->data;
		};

		auto operator++() -> Iterator & {
			node = node->next;
			return *this;
		};

		auto operator==(const Iterator &other) -> bool {
			return node == other.node;
		};

		auto operator!=(const Iterator &other) -> bool {
			return node != other.node;
		};

		private:
		std::shared_ptr<Node> node;
	};

	auto begin() -> Iterator {
		return Iterator{head_};
	};

	auto end() -> Iterator {
		return Iterator{nullptr};
	};

	private:
	std::shared_ptr<Node> head_;
	std::shared_ptr<Node> tail_;
	int size_;

	auto initializeList(std::shared_ptr<Node> node) -> void {
		head_ = node;
		tail_ = node;

		++size_;
	}

	auto insertNodeAtHead(std::shared_ptr<Node> newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = head_;
		newNode->prev = nullptr;

		head_->prev = newNode;
		head_ = newNode;

		++size_;
	}

	auto insertNodeAtTail(std::shared_ptr<Node> newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = nullptr;
		newNode->prev = tail_;

		tail_->next = newNode;
		tail_ = newNode;

		++size_;
	}

	auto insertNodeBefore(
		std::shared_ptr<Node> node, std::shared_ptr<Node> newNode
	) -> void {
		if (isEmpty()) return initializeList(newNode);
		if (node == head_) return insertNodeAtHead(newNode);

		newNode->next = node;
		newNode->prev = node->prev;

		node->prev->next = newNode;
		node->prev = newNode;

		++size_;
	}

	auto insertNodeAfter(
		std::shared_ptr<Node> node, std::shared_ptr<Node> newNode
	) -> void {
		if (isEmpty()) return initializeList(newNode);
		if (node == tail_) return insertNodeAtTail(newNode);

		newNode->prev = node;
		newNode->next = node->next;

		node->next->prev = newNode;
		node->next = newNode;

		++size_;
	}

	auto getNode(const int &index) -> std::shared_ptr<Node> {
		if (index < 0 || index >= size_)
			throw std::out_of_range("Index out of range");

		std::shared_ptr<Node> temp{head_};

		for (int i{0}; i < index; ++i) {
			temp = temp->next;
		}

		return temp;
	}

	auto removeNode(std::shared_ptr<Node> node) -> void {
		if (!node) return;

		if (node == head_) {
			head_ = node->next;
		} else if (node == tail_) {
			tail_ = node->prev;
		} else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		node = nullptr;
		--size_;
	}
};

#endif
