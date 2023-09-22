#include "data_structures/queue.hpp"

#include <cstdlib>
#include <vector>

#include "catch2/catch_test_macros.hpp"

TEST_CASE("Queue", "[Queue]") {
	SECTION("enqueue") {
		Queue<int> queue;

		queue.enqueue(1);
		REQUIRE(queue.peek() == 1);

		queue.enqueue(2);
		REQUIRE(queue.peek() == 1);
		queue.dequeue();
		REQUIRE(queue.peek() == 2);

		queue.enqueue(3);
		REQUIRE(queue.peek() == 2);
		queue.dequeue();
		REQUIRE(queue.peek() == 3);
	}

	SECTION("dequeue") {
		Queue<int> queue;

		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		REQUIRE(queue.dequeue() == 1);
		REQUIRE(queue.dequeue() == 2);
		REQUIRE(queue.dequeue() == 3);
	}

	SECTION("peek") {
		Queue<int> queue;

		queue.enqueue(1);
		REQUIRE(queue.peek() == 1);

		queue.enqueue(2);
		REQUIRE(queue.peek() == 1);

		queue.enqueue(3);
		REQUIRE(queue.peek() == 1);
	}

	SECTION("isEmpty") {
		Queue<int> queue;

		REQUIRE(queue.isEmpty());

		queue.enqueue(1);

		REQUIRE_FALSE(queue.isEmpty());
	}

	SECTION("random") {
		Queue<int> queue;
		std::vector<int> random;

		for (size_t i{0}; i < 100; ++i) {
			int value{rand() % 100};
			queue.enqueue(value);
			random.push_back(value);
		}

		for (size_t i{0}; i < 100; ++i) {
			REQUIRE(queue.peek() == random[i]);
			REQUIRE(queue.dequeue() == random[i]);
		}
	}
}
