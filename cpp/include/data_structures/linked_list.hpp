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
		Node(const T data) : data{data}, next{nullptr}, prev{nullptr} {};

		T data;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
	};

	using NodePtr = std::shared_ptr<Node>;

	public:
	class Iterator {
		public:
		Iterator(NodePtr node) : node{node} {};

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
		NodePtr node;
	};

	LinkedList() : head_{nullptr}, tail_{nullptr}, size_{0} {};

	LinkedList(const LinkedList<T> &other)
		: head_{nullptr}, tail_{nullptr}, size_{0} {
		for (const T &data : other) {
			pushBack(data);
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
			pushBack(*it);
		}
	}

	LinkedList(std::initializer_list<T> values)
		: head_{nullptr}, tail_{nullptr}, size_{0} {
		for (const T &data : values) {
			pushBack(data);
		}
	}

	~LinkedList() {
		clear();
	}

	auto operator=(const LinkedList<T> &other) -> LinkedList<T> & {
		if (this != &other) {
			clear();

			for (const T &data : other) {
				pushBack(data);
			}
		}

		return *this;
	}

	auto operator=(LinkedList<T> &&other) -> LinkedList<T> & {
		if (this != &other) {
			clear();

			head_ = std::move(other.head_);
			tail_ = std::move(other.tail_);
			size_ = other.size_;

			other.clear();
		}

		return *this;
	}

	auto operator[](const size_t &i) -> T & {
		return getNode(i)->data;
	}

	auto operator[](const size_t &i) const -> const T & {
		return getNode(i)->data;
	}

	auto operator==(const LinkedList<T> &other) const -> bool {
		if (size_ != other.size_) return false;

		NodePtr thisNode{head_};
		NodePtr otherNode{other.head_};

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

	auto size() const -> size_t {
		return size_;
	};

	auto pushFront(const T &data) -> T & {
		NodePtr newNode{std::make_shared<Node>(data)};

		pushNodeAtHead(newNode);

		return newNode->data;
	};

	auto pushBack(const T &data) -> T & {
		NodePtr newNode{std::make_shared<Node>(data)};

		pushNodeAtTail(newNode);

		return newNode->data;
	};

	auto pushAfter(const T &data, const size_t &i) -> T & {
		NodePtr newNode{std::make_shared<Node>(data)};

		pushNodeAfter(getNode(i), newNode);

		return newNode->data;
	};

	auto pushBefore(const T &data, const size_t &i) -> void {
		NodePtr newNode{};

		pushNodeBefore(getNode(i), std::make_shared<Node>(data));
	}

	auto updateFront(const T &data) -> void {
		head_->data = data;
	};

	auto updateBack(const T &data) -> void {
		tail_->data = data;
	};

	auto popFront() -> T {
		return popNode(head_);
	};

	auto popBack() -> T {
		return popNode(tail_);
	};

	auto pop(const size_t &i) -> T {
		return popNode(getNode(i));
	};

	auto sort() -> void {
		quickSort(*this, 0, size() - 1);
	}

	auto reverse() -> void {
		NodePtr temp{head_};

		head_ = tail_;
		tail_ = temp;

		while (temp) {
			std::swap(temp->prev, temp->next);
			temp = temp->prev;
		}
	};

	auto isEmpty() const -> bool {
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
	NodePtr head_;
	NodePtr tail_;
	size_t size_;

	auto initializeList(const NodePtr &node) -> void {
		head_ = node;
		tail_ = node;

		++size_;
	}

	auto pushNodeAtHead(const NodePtr &newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = head_;
		newNode->prev = nullptr;

		head_->prev = newNode;
		head_ = newNode;

		++size_;
	}

	auto pushNodeAtTail(const NodePtr &newNode) -> void {
		if (isEmpty()) return initializeList(newNode);

		newNode->next = nullptr;
		newNode->prev = tail_;

		tail_->next = newNode;
		tail_ = newNode;

		++size_;
	}

	auto pushNodeBefore(
		const NodePtr &node, const std::shared_ptr<Node> &newNode
	) -> void {
		if (isEmpty()) return initializeList(newNode);
		if (node == head_) return pushNodeAtHead(newNode);

		newNode->next = node;
		newNode->prev = node->prev;

		node->prev->next = newNode;
		node->prev = newNode;

		++size_;
	}

	auto pushNodeAfter(
		const NodePtr &node, const std::shared_ptr<Node> &newNode
	) -> void {
		if (isEmpty()) return initializeList(newNode);
		if (node == tail_) return pushNodeAtTail(newNode);

		newNode->prev = node;
		newNode->next = node->next;

		node->next->prev = newNode;
		node->next = newNode;

		++size_;
	}

	auto getNode(size_t i) const -> NodePtr {
		if (i >= size_) throw std::out_of_range{"Index out of range"};

		if (i == 0) return head_;
		if (i == size_ - 1) return tail_;

		NodePtr temp{head_};

		while (i) {
			temp = temp->next;
			--i;
		}

		return temp;
	}

	auto popNode(NodePtr node) -> T {
		T data = node->data;

		if (node == head_) {
			head_->prev = nullptr;
			head_ = head_->next;
		} else if (node == tail_) {
			tail_->next = nullptr;
			tail_ = tail_->prev;
		} else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		--size_;

		return data;
	}

	auto mergeSort(LinkedList<T> &list) -> void {
		if (list.size() <= 1) return;

		Iterator mid = list.begin() + static_cast<int>(list.size() / 2);
		LinkedList<T> left{list.begin(), mid};
		LinkedList<T> right{mid, list.end()};

		mergeSort(left);
		mergeSort(right);

		LinkedList<T> merged;
		size_t l{0};
		size_t r{0};

		while (l < left.size() && r < right.size()) {
			if (left[l] < right[r]) merged.pushBack(left[l++]);
			else merged.pushBack(right[r++]);
		}

		while (l < left.size()) merged.pushBack(left[l++]);
		while (r < right.size()) merged.pushBack(right[r++]);

		list = std::move(merged);
	}

	auto quickSort(LinkedList<T> &list, size_t left, size_t right) -> void {
		if (left >= right) return;

		T pivot{list[right]};
		size_t i{left};

		for (size_t j{left}; j < right; ++j) {
			if (list[j] <= pivot) std::swap(list[i++], list[j]);
		}

		std::swap(list[i], list[right]);

		quickSort(list, left, i == 0 ? 0 : i - 1);
		quickSort(list, i, right);
	}
};

#endif
