#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>
#include "data_structures/linked_list.hpp"

template <typename T>
class Queue {
	public:
	auto enqueue(T data) -> void {
		data_.pushBack(data);
	};

	auto dequeue() -> T {
		if (isEmpty()) throw std::runtime_error{"Queue is empty"};
		return data_.popFront();
	}

	auto peek() -> T {
		if (isEmpty()) throw std::runtime_error{"Queue is empty"};
		return data_.front();
	}

	auto isEmpty() -> bool {
		return data_.isEmpty();
	}

	private:
	LinkedList<T> data_;
};

#endif
