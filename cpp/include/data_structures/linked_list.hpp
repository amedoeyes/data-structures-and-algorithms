#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <type_traits>

template <typename T>
class LinkedList {
	private:
	class Node {
		public:
		Node(T data) : data{data}, next{nullptr}, prev{nullptr} {};

		T data;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
	};

	public:
	class Iterator {
		public:
		Iterator(std::shared_ptr<Node> node) : node{node} {};

		auto operator*() -> T & {
			return node->data;
		};

		auto operator+(const int &steps) const -> Iterator {
			Iterator temp{*this};

			for (int i{0}; i < steps; ++i) {
				++temp;
			}

			return temp;
		}

		auto operator++() -> Iterator & {
			node = node->next;
			return *this;
		};

		auto operator!=(const Iterator &other) const -> bool {
			return node != other.node;
		};

		private:
		std::shared_ptr<Node> node;
	};

	LinkedList() : head_{nullptr}, tail_{nullptr}, size_{0} {};

	LinkedList(const LinkedList<T> &other)
		: head_{nullptr}, tail_{nullptr}, size_{0} {
		for (const T &data : other) {
			insertBack(data);
		}
	}

	LinkedList(LinkedList<T> &&other)
		: head_{std::move(other.head_)},
		  tail_{std::move(other.tail_)},
		  size_{other.size_} {
		other.clear();
	}

	LinkedList(const Iterator &first, const Iterator &last)
		: head_{nullptr}, tail_{nullptr}, size_{0} {
		for (Iterator it{first}; it != last; ++it) {
			insertBack(*it);
		}
	}

	LinkedList(std::initializer_list<T> values)
		: head_{nullptr}, tail_{nullptr}, size_{0} {
		for (const T &data : values) {
			insertBack(data);
		}
	}

	auto operator=(const LinkedList<T> &other) -> LinkedList<T> & {
		if (this != &other) {
			clear();

			for (const T &data : other) {
				insertBack(data);
			}
		}

		return *this;
	}

	LinkedList<T> &operator=(LinkedList<T> &&other) {
		if (this != &other) {
			clear();

			head_ = std::move(other.head_);
			tail_ = std::move(other.tail_);
			size_ = other.size_;

			other.clear();
		}

		return *this;
	}

	auto operator[](const int &index) -> T & {
		return getNodeAt(index)->data;
	}

	auto operator==(const LinkedList<T> &other) const -> bool {
		if (size_ != other.size_) return false;

		auto thisNode{head_};
		auto otherNode{other.head_};

		while (thisNode && otherNode) {
			if (thisNode->data != otherNode->data) return false;

			thisNode = thisNode->next;
			otherNode = otherNode->next;
		}

		return true;
	}

	auto front() const -> const T & {
		return head_->data;
	};

	auto back() const -> const T & {
		return tail_->data;
	};

	auto size() const -> const int {
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

		insertNodeAfter(getNodeAt(index), newNode);
	};

	auto insertBefore(const T &data, const int &index) -> void {
		std::shared_ptr<Node> newNode{std::make_shared<Node>(data)};

		if (index == 0) return insertNodeBefore(head_, newNode);
		if (index == size_ - 1) return insertNodeBefore(tail_, newNode);

		insertNodeBefore(getNodeAt(index), newNode);
	}

	auto updateFront(const T &data) -> void {
		head_->data = data;
	};

	auto updateBack(const T &data) -> void {
		tail_->data = data;
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

		removeNode(getNodeAt(index));
	};

	auto sort() -> void {
		mergeSort(*this);
	}

	auto reverse() -> void {
		std::shared_ptr<Node> temp{head_};

		head_ = tail_;
		tail_ = temp;

		while (temp) {
			std::swap(temp->prev, temp->next);
			temp = temp->prev;
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

	auto begin() const -> const Iterator {
		return Iterator{head_};
	};

	auto end() const -> const Iterator {
		return Iterator{nullptr};
	};

	private:
	std::shared_ptr<Node> head_;
	std::shared_ptr<Node> tail_;
	size_t size_;

	auto initializeList(const std::shared_ptr<Node> &node) -> void {
		head_ = node;
		tail_ = node;

		++size_;
	}

	auto insertNodeAtHead(const std::shared_ptr<Node> &newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = head_;
		newNode->prev = nullptr;

		head_->prev = newNode;
		head_ = newNode;

		++size_;
	}

	auto insertNodeAtTail(const std::shared_ptr<Node> &newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = nullptr;
		newNode->prev = tail_;

		tail_->next = newNode;
		tail_ = newNode;

		++size_;
	}

	auto insertNodeBefore(
		const std::shared_ptr<Node> &node, const std::shared_ptr<Node> &newNode
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
		const std::shared_ptr<Node> &node, const std::shared_ptr<Node> &newNode
	) -> void {
		if (isEmpty()) return initializeList(newNode);
		if (node == tail_) return insertNodeAtTail(newNode);

		newNode->prev = node;
		newNode->next = node->next;

		node->next->prev = newNode;
		node->next = newNode;

		++size_;
	}

	auto getNodeAt(const int &index) const -> std::shared_ptr<Node> {
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

	auto mergeSort(LinkedList<T> &list) -> void {
		if (list.size() <= 1) return;

		auto mid = list.begin() + list.size() / 2;
		LinkedList<T> left{list.begin(), mid};
		LinkedList<T> right{mid, list.end()};

		mergeSort(left);
		mergeSort(right);

		LinkedList<T> merged;
		int l{0};
		int r{0};

		while (l < left.size() && r < right.size()) {
			if (left[l] < right[r]) merged.insertBack(left[l++]);
			else merged.insertBack(right[r++]);
		}

		while (l < left.size()) merged.insertBack(left[l++]);
		while (r < right.size()) merged.insertBack(right[r++]);

		list = std::move(merged);
	}
};

#endif
