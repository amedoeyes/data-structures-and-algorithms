#include "data_structures/linked_list.hpp"

#include <algorithm>
#include <vector>

#include "catch2/catch_test_macros.hpp"

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
		REQUIRE(list[0] == 1);
		REQUIRE(list[1] == 2);
		REQUIRE(list[2] == 3);
	}

	SECTION("operator=") {
		LinkedList<int> list1{{1, 2, 3}};
		LinkedList<int> list2;

		list2 = list1;

		REQUIRE(list1 == list2);

		list1.pushBack(4);

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

		list1.pushBack(1);

		REQUIRE_FALSE(list1 == list2);
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

	SECTION("pushBack") {
		LinkedList<int> list;

		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);

		REQUIRE(list.size() == 3);
		REQUIRE(list[0] == 1);
		REQUIRE(list[1] == 2);
		REQUIRE(list[2] == 3);
	}

	SECTION("pushFront") {
		LinkedList<int> list;

		list.pushFront(1);
		list.pushFront(2);
		list.pushFront(3);

		REQUIRE(list.size() == 3);
		REQUIRE(list[0] == 3);
		REQUIRE(list[1] == 2);
		REQUIRE(list[2] == 1);
	}

	SECTION("pushBefore") {
		LinkedList<int> list{{1, 2, 3}};

		list.pushBefore(0, 0);

		REQUIRE(list.size() == 4);
		REQUIRE(list[0] == 0);

		list.pushBefore(4, 3);

		REQUIRE(list.size() == 5);
		REQUIRE(list[3] == 4);
		REQUIRE(list[4] == 3);

		list.pushBefore(5, 2);

		REQUIRE(list.size() == 6);
		REQUIRE(list[2] == 5);
	}

	SECTION("pushAfter") {
		LinkedList<int> list{{1, 2, 3}};

		list.pushAfter(4, 2);

		REQUIRE(list.size() == 4);
		REQUIRE(list[3] == 4);

		list.pushAfter(0, 0);

		REQUIRE(list.size() == 5);
		REQUIRE(list[0] == 1);
		REQUIRE(list[1] == 0);

		list.pushAfter(5, 2);

		REQUIRE(list.size() == 6);
		REQUIRE(list[3] == 5);
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

	SECTION("popFront") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.popFront() == 1);
		REQUIRE(list.front() == 2);
		REQUIRE(list.size() == 2);

		REQUIRE(list.popFront() == 2);
		REQUIRE(list.front() == 3);
		REQUIRE(list.size() == 1);

		REQUIRE(list.popFront() == 3);
		REQUIRE(list.size() == 0);
	}

	SECTION("popBack") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.popBack() == 3);
		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 2);
		REQUIRE(list.size() == 2);

		REQUIRE(list.popBack() == 2);
		REQUIRE(list.back() == 1);
		REQUIRE(list.size() == 1);

		REQUIRE(list.popBack() == 1);
		REQUIRE(list.size() == 0);
	}

	SECTION("pop") {
		LinkedList<int> list{{1, 2, 3}};

		REQUIRE(list.pop(1) == 2);
		REQUIRE(list[1] == 3);
		REQUIRE(list.size() == 2);

		REQUIRE(list.pop(1) == 3);
		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 1);
		REQUIRE(list.size() == 1);

		REQUIRE(list.pop(0) == 1);
		REQUIRE(list.size() == 0);
	}

	SECTION("sort") {
		LinkedList<int> list{{4, 2, 1, 3}};

		list.sort();

		REQUIRE(list[0] == 1);
		REQUIRE(list[1] == 2);
		REQUIRE(list[2] == 3);
		REQUIRE(list[3] == 4);
	}

	SECTION("reverse") {
		LinkedList<int> list{{1, 2, 3, 4}};

		list.reverse();

		REQUIRE(list[0] == 4);
		REQUIRE(list[1] == 3);
		REQUIRE(list[2] == 2);
		REQUIRE(list[3] == 1);
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
		REQUIRE(iterated[0] == 1);
		REQUIRE(iterated[1] == 2);
		REQUIRE(iterated[2] == 3);
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
		REQUIRE(iterated[0] == 1);
		REQUIRE(iterated[1] == 2);
		REQUIRE(iterated[2] == 3);
	}

	SECTION("iterator modify") {
		LinkedList<int> list{{1, 2, 3}};

		for (int& it : list) {
			it *= 2;
		}

		REQUIRE(list[0] == 2);
		REQUIRE(list[1] == 4);
		REQUIRE(list[2] == 6);
	}

	SECTION("clear") {
		LinkedList<int> list{{1, 2, 3}};

		list.clear();

		REQUIRE(list.isEmpty());
	}

	SECTION("isEmpty") {
		LinkedList<int> list;

		REQUIRE(list.isEmpty());

		list.pushBack(1);

		REQUIRE_FALSE(list.isEmpty());
	}

	SECTION("random") {
		LinkedList<int> list;
		std::vector<int> random;

		for (size_t i{0}; i < 100; i++) {
			int val{rand() % 1000};
			list.pushBack(val);
			random.push_back(val);
		}

		for (size_t i{0}; i < 100; i++) {
			REQUIRE(list[i] == random[i]);
		}
	}
}
