

#include "data_structures/linked_list.hpp"

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

auto initializeList() -> LinkedList<int> {
	LinkedList<int> list;

	list.insertBack(1);
	list.insertBack(2);
	list.insertBack(3);

	return list;
}

TEST_CASE("LinkedList", "[LinkedList]") {
	SECTION("front") {
		LinkedList<int> list = initializeList();

		REQUIRE(list.front() == 1);
	}

	SECTION("getLast") {
		LinkedList<int> list = initializeList();

		REQUIRE(list.back() == 3);
	}

	SECTION("get") {
		LinkedList<int> list = initializeList();

		REQUIRE(list.get(0) == 1);
		REQUIRE(list.get(1) == 2);
		REQUIRE(list.get(2) == 3);

		REQUIRE_THROWS(list.get(-1));
		REQUIRE_THROWS(list.get(4));
	}

	SECTION("size") {
		LinkedList<int> list = initializeList();

		REQUIRE(list.size() == 3);

		list.insertBack(4);

		REQUIRE(list.size() == 4);
	}

	SECTION("insertBack") {
		LinkedList<int> list = initializeList();

		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 3);
		REQUIRE(list.size() == 3);
	}

	SECTION("insertFront") {
		LinkedList<int> list;

		list.insertFront(1);
		list.insertFront(2);
		list.insertFront(3);

		REQUIRE(list.front() == 3);
		REQUIRE(list.back() == 1);
		REQUIRE(list.size() == 3);
	}

	SECTION("insertBefore") {
		LinkedList<int> list = initializeList();

		list.insertBefore(4, 1);

		REQUIRE(list.get(1) == 4);
		REQUIRE(list.size() == 4);
	}

	SECTION("insertAfter") {
		LinkedList<int> list = initializeList();

		list.insertAfter(4, 1);

		REQUIRE(list.get(2) == 4);
		REQUIRE(list.size() == 4);
	}

	SECTION("updateFront") {
		LinkedList<int> list = initializeList();

		list.updateFront(4);

		REQUIRE(list.front() == 4);
	}

	SECTION("updateBack") {
		LinkedList<int> list = initializeList();

		list.updateBack(4);

		REQUIRE(list.back() == 4);
	}

	SECTION("update") {
		LinkedList<int> list = initializeList();

		list.update(0, 4);
		list.update(1, 5);
		list.update(2, 6);

		REQUIRE(list.front() == 4);
		REQUIRE(list.get(1) == 5);
		REQUIRE(list.back() == 6);
	}

	SECTION("removeFront") {
		LinkedList<int> list = initializeList();

		list.removeFront();

		REQUIRE(list.front() == 2);
		REQUIRE(list.size() == 2);

		list.removeFront();

		REQUIRE(list.front() == 3);
		REQUIRE(list.size() == 1);

		list.removeFront();

		REQUIRE(list.size() == 0);
	}

	SECTION("removeBack") {
		LinkedList<int> list = initializeList();

		list.removeBack();

		REQUIRE(list.back() == 2);
		REQUIRE(list.size() == 2);

		list.removeBack();

		REQUIRE(list.back() == 1);
		REQUIRE(list.size() == 1);

		list.removeBack();

		REQUIRE(list.size() == 0);
	}

	SECTION("remove") {
		LinkedList<int> list = initializeList();

		list.remove(1);

		REQUIRE(list.get(1) == 3);
		REQUIRE(list.size() == 2);

		list.remove(1);

		REQUIRE(list.back() == 1);
		REQUIRE(list.front() == 1);
		REQUIRE(list.size() == 1);

		list.remove(0);

		REQUIRE(list.isEmpty());
	}

	SECTION("reverse") {
		LinkedList<int> list = initializeList();

		list.reverse();

		REQUIRE(list.get(0) == 3);
		REQUIRE(list.get(1) == 2);
		REQUIRE(list.get(2) == 1);
	}

	SECTION("traverse") {
		LinkedList<int> list = initializeList();

		int count{0};
		std::vector<int> traversal;

		list.traverse([&count, &traversal](int data) {
			traversal.push_back(data);
			count++;
		});

		REQUIRE(count == 3);
		REQUIRE(traversal[0] == 1);
		REQUIRE(traversal[1] == 2);
		REQUIRE(traversal[2] == 3);
	}

	SECTION("iterator") {
		LinkedList<int> list = initializeList();

		int count{0};
		std::vector<int> iterated;

		for (const auto &it : list) {
			iterated.push_back(it);
			count++;
		}

		REQUIRE(count == 3);
		REQUIRE(iterated[0] == 1);
		REQUIRE(iterated[1] == 2);
		REQUIRE(iterated[2] == 3);
	}

	SECTION("clear") {
		LinkedList<int> list = initializeList();

		list.clear();

		REQUIRE(list.isEmpty());
	}

	SECTION("isEmpty") {
		LinkedList<int> list;

		REQUIRE(list.isEmpty());

		list.insertBack(1);

		REQUIRE_FALSE(list.isEmpty());
	}

	SECTION("random values") {
		LinkedList<int> list;
		std::vector<int> random;

		for (int i{0}; i < 100; i++) {
			int val = rand() % 1000;
			list.insertBack(val);
			random.push_back(val);
		}

		for (int i{0}; i < 100; i++) {
			REQUIRE(list.get(i) == random[i]);
		}
	}
}
