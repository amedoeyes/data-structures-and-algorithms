#include "data_structures/linked_list.hpp"

#include <algorithm>
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
	SECTION("copy") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2{list1};

		REQUIRE(list1 == list2);
	}

	SECTION("move") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2{std::move(list1)};

		REQUIRE(list1.size() == 0);
		REQUIRE(list2.size() == 3);
	}

	SECTION("initializer_list") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.size() == 3);

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == i + 1);
		}
	}

	SECTION("front") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.front() == 1);
	}

	SECTION("back") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.back() == 3);
	}

	SECTION("size") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.size() == 3);
	}

	SECTION("insertBack") {
		LinkedList<int> list;

		list.insertBack(1);
		list.insertBack(2);
		list.insertBack(3);

		REQUIRE(list.size() == 3);

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == i + 1);
		}
	}

	SECTION("insertFront") {
		LinkedList<int> list;

		list.insertFront(1);
		list.insertFront(2);
		list.insertFront(3);

		REQUIRE(list.size() == 3);

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == list.size() - i);
		}
	}

	SECTION("insertBefore") {
		LinkedList<int> list{{1, 2, 3}};

		list.insertBefore(4, 1);

		REQUIRE(list[1] == 4);
		REQUIRE(list.size() == 4);
	}

	SECTION("insertAfter") {
		LinkedList<int> list{{1, 2, 3}};

		list.insertAfter(4, 1);

		REQUIRE(list[2] == 4);
		REQUIRE(list.size() == 4);
	}

	SECTION("updateFront") {
		LinkedList<int> list{{1, 2, 3}};

		list.updateFront(4);

		REQUIRE(list.front() == 4);
	}

	SECTION("updateBack") {
		LinkedList<int> list{{1, 2, 3}};

		list.updateBack(4);

		REQUIRE(list.back() == 4);
	}

	SECTION("removeFront") {
		LinkedList<int> list{{1, 2, 3}};

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
		LinkedList<int> list{{1, 2, 3}};

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
		LinkedList<int> list{{1, 2, 3}};

		list.remove(1);

		REQUIRE(list[1] == 3);
		REQUIRE(list.size() == 2);

		list.remove(1);

		REQUIRE(list.back() == 1);
		REQUIRE(list.front() == 1);
		REQUIRE(list.size() == 1);

		list.remove(0);

		REQUIRE(list.isEmpty());
	}

	SECTION("sort") {
		LinkedList<int> list{{4, 2, 1, 3}};

		list.sort();

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == i + 1);
		}
	}

	SECTION("reverse") {
		LinkedList<int> list{{1, 2, 3}};

		list.reverse();

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == list.size() - i);
		}
	}

	SECTION("iterator begin end") {
		LinkedList<int> list{{1, 2, 3}};

		int count{0};
		std::vector<int> iterated;

		for (LinkedList<int>::Iterator it{list.begin()}; it != list.end();
			 ++it) {
			iterated.push_back(*it);
			count++;
		}

		REQUIRE(count == 3);

		for (int i{0}; i < iterated.size(); ++i) {
			REQUIRE(iterated[i] == i + 1);
		}
	}

	SECTION("iterator :") {
		LinkedList<int> list{{1, 2, 3}};

		int count{0};
		std::vector<int> iterated;

		for (int it : list) {
			iterated.push_back(it);
			count++;
		}

		REQUIRE(count == 3);

		for (int i{0}; i < iterated.size(); ++i) {
			REQUIRE(iterated[i] == i + 1);
		}
	}

	SECTION("iterator modify") {
		LinkedList<int> list{{1, 2, 3}};

		for (int& it : list) {
			it *= 2;
		}

		for (int i{0}; i < list.size(); ++i) {
			REQUIRE(list[i] == (i+1) * 2);
		}
	}

	SECTION("clear") {
		LinkedList<int> list{{1, 2, 3}};

		list.clear();

		REQUIRE(list.isEmpty());
	}

	SECTION("isEmpty") {
		LinkedList<int> list;

		REQUIRE(list.isEmpty());

		list.insertBack(1);

		REQUIRE_FALSE(list.isEmpty());
	}

	SECTION("operator=") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2;

		list2 = list1;

		REQUIRE(list1 == list2);

		list1.insertBack(4);

		REQUIRE_FALSE(list1 == list2);

		list2 = list1;

		REQUIRE(list1 == list2);
	}

	SECTION("operator= move") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2;

		list2 = std::move(list1);

		REQUIRE(list1.size() == 0);
		REQUIRE(list2.size() == 3);
	}

	SECTION("operator[]") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list[0] == 1);
		REQUIRE(list[1] == 2);
		REQUIRE(list[2] == 3);

		list[0] = 4;
		list[1] = 5;
		list[2] = 6;

		REQUIRE(list[0] == 4);
		REQUIRE(list[1] == 5);
		REQUIRE(list[2] == 6);

		REQUIRE_THROWS(list[3]);
	}

	SECTION("operator==") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2{{1, 2, 3}};

		REQUIRE(list1 == list2);

		list1.insertBack(1);

		REQUIRE_FALSE(list1 == list2);
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
			REQUIRE(list[i] == random[i]);
		}
	}
}
