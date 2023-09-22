#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

#include "data_structures/linked_list.hpp"

template <typename T>
class Stack {
	public:
	auto push(const T& data) -> void {
		data_.pushBack(data);
	}

	auto pop() -> T {
		if (isEmpty()) throw std::runtime_error{"Stack is empty"};
		return data_.popBack();
	}

	auto peek() const -> T {
		if (isEmpty()) throw std::runtime_error{"Stack is empty"};
		return data_.back();
	}

	auto isEmpty() const -> bool {
		return data_.isEmpty();
	}

	private:
	LinkedList<T> data_;
};

#endif
