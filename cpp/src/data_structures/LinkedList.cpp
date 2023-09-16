#include "data_structures/LinkedList.hpp"
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>

// PUBLIC

template <typename T>
Node<T>::Node(T data) : data{data}, next{nullptr}, prev{nullptr} {}

template <typename T>
LinkedList<T>::LinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

template <typename T>
auto LinkedList<T>::getFirst() -> T {
	return head->data;
}

template <typename T>
auto LinkedList<T>::getLast() -> T {
	return tail->data;
}

template <typename T>
auto LinkedList<T>::get(const int &index) -> T {
	return getNode(index)->data;
}

template <typename T>
auto LinkedList<T>::getSize() -> int {
	return size;
}

template <typename T>
auto LinkedList<T>::insertFirst(const T &data) -> void {
	std::shared_ptr<Node<T>> newNode{std::make_shared<Node<T>>(data)};

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}

	size++;
}

template <typename T>
auto LinkedList<T>::insertLast(const T &data) -> void {
	std::shared_ptr<Node<T>> newNode{std::make_shared<Node<T>>(data)};

	if (!head) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	size++;
}

template <typename T>
auto LinkedList<T>::insert(const T &data, const int &index) -> void {
	if (index == 0) {
		insertFirst(data);
		return;
	}

	std::shared_ptr<Node<T>> newNode{std::make_shared<Node<T>>(data)};
	std::shared_ptr<Node<T>> targetNode{getNode(index)};
	std::shared_ptr<Node<T>> prevNode{targetNode->prev};

	newNode->prev = prevNode;
	newNode->next = targetNode;

	prevNode->next = newNode;
	targetNode->prev = newNode;

	size++;
}

template <typename T>
auto LinkedList<T>::updateFirst(const T &data) -> void {
	head->data = data;
}

template <typename T>
auto LinkedList<T>::updateLast(const T &data) -> void {
	tail->data = data;
}

template <typename T>
auto LinkedList<T>::update(const int &index, const T &data) -> void {
	if (index == 0) return updateFirst(data);
	if (index == size - 1) return updateLast(data);

	getNode(index)->data = data;
}

template <typename T>
auto LinkedList<T>::removeFirst() -> void {
	if (head) {
		head = head->next;

		if (head) head->prev = nullptr;
	}

	size--;
}

template <typename T>
auto LinkedList<T>::removeLast() -> void {
	if (tail) {
		tail = tail->prev;

		if (tail) tail->next = nullptr;
	}

	size--;
}

template <typename T>
auto LinkedList<T>::remove(const int &index) -> void {
	if (index == 0) return removeFirst();
	if (index == size - 1) return removeLast();

	std::shared_ptr<Node<T>> targetNode{getNode(index)};
	std::shared_ptr<Node<T>> prevNode{targetNode->prev};
	std::shared_ptr<Node<T>> nextNode{targetNode->next};

	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	targetNode->prev = nullptr;
	targetNode->next = nullptr;

	size--;
}

template <typename T>
auto LinkedList<T>::reverse() -> void {
	std::shared_ptr<Node<T>> temp{head};

	head = tail;
	tail = temp;

	while (temp) {
		std::swap(temp->prev, temp->next);
		temp = temp->prev;
	}
}

template <typename T>
auto LinkedList<T>::traverse(const std::function<void(T)> &visit) -> void {
	for (const T &it : *this) {
		visit(it);
	}
}

template <typename T>
auto LinkedList<T>::isEmpty() -> bool {
	return size == 0;
}

template <typename T>
auto LinkedList<T>::clear() -> void {
	while (head) {
		head->prev = nullptr;
		head = head->next;
	}

	tail = nullptr;
	size = 0;
}

template <typename T>
LinkedList<T>::Iterator::Iterator(std::shared_ptr<Node<T>> node) : node{node} {}

template <typename T>
auto LinkedList<T>::Iterator::operator++() -> Iterator & {
	node = node->next;
	return *this;
}

template <typename T>
auto LinkedList<T>::Iterator::operator!=(const Iterator &other) -> bool {
	return node != other.node;
}

template <typename T>
auto LinkedList<T>::Iterator::operator==(const Iterator &other) -> bool {
	return node == other.node;
}

template <typename T>
auto LinkedList<T>::Iterator::operator*() -> T {
	return node->data;
}

template <typename T>
auto LinkedList<T>::begin() -> Iterator {
	return Iterator{head};
}

template <typename T>
auto LinkedList<T>::end() -> Iterator {
	return Iterator{nullptr};
}

// PRIVATE

template <typename T>
auto LinkedList<T>::getNode(const int &index) -> std::shared_ptr<Node<T>> {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range: " + std::to_string(index));
	};

	std::shared_ptr<Node<T>> temp{head};

	for (int i{0}; i < index; ++i) {
		temp = temp->next;
	}

	return temp;
}

template class LinkedList<int>;
template class LinkedList<long>;
template class LinkedList<long long>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<std::string>;
