
#include "data_structures/stack.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("stack") {
	SECTION("push") {
		Stack<int> stack;

		stack.push(1);
		REQUIRE(stack.peek() == 1);

		stack.push(2);
		REQUIRE(stack.peek() == 2);

		stack.push(3);
		REQUIRE(stack.peek() == 3);
	}

	SECTION("pop") {
		Stack<int> stack;

		stack.push(1);
		stack.push(2);
		stack.push(3);

		REQUIRE(stack.pop() == 3);
		REQUIRE(stack.pop() == 2);
		REQUIRE(stack.pop() == 1);
	}

	SECTION("peek") {
		Stack<int> stack;

		stack.push(1);
		REQUIRE(stack.peek() == 1);

		stack.push(2);
		REQUIRE(stack.peek() == 2);

		stack.push(3);
		REQUIRE(stack.peek() == 3);
	}

	SECTION("isEmpty") {
		Stack<int> stack;

		REQUIRE(stack.isEmpty());

		stack.push(1);

		REQUIRE_FALSE(stack.isEmpty());
	}

	SECTION("random") {
		Stack<int> stack;
		std::vector<int> random;

		for (size_t i{0}; i < 100; ++i) {
			int val{rand() % 1000};
			stack.push(val);
			random.push_back(val);
		}

		for (size_t i{0}; i < 10; ++i) {
			REQUIRE(stack.pop() == random.back());
			random.pop_back();
		}
	}
}
