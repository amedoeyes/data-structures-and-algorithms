#include "data_structures/LinkedList.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LinkedList", "[LinkedList]") {

	SECTION("getFirst") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		REQUIRE(list.getFirst() == 1);
	}

	SECTION("getLast") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		REQUIRE(list.getLast() == 3);
	}

	SECTION("get") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		REQUIRE(list.get(0) == 1);
		REQUIRE(list.get(1) == 2);
		REQUIRE(list.get(2) == 3);

		REQUIRE_THROWS(list.get(-1));
		REQUIRE_THROWS(list.get(4));
	}

	SECTION("getSize") {
		LinkedList<int> list;

		REQUIRE(list.getSize() == 0);

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		REQUIRE(list.getSize() == 3);
	}

	SECTION("insertLast") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		REQUIRE(list.getFirst() == 1);
		REQUIRE(list.getLast() == 3);
		REQUIRE(list.getSize() == 3);
	}

	SECTION("insertFirst") {
		LinkedList<int> list;

		list.insertFirst(1);
		list.insertFirst(2);
		list.insertFirst(3);

		REQUIRE(list.getFirst() == 3);
		REQUIRE(list.getLast() == 1);
		REQUIRE(list.getSize() == 3);
	}

	SECTION("insert") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.insert(4, 1);

		REQUIRE(list.getSize() == 4);
		REQUIRE(list.get(1) == 4);
	}

	SECTION("updateFirst") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.updateFirst(4);

		REQUIRE(list.getFirst() == 4);
	}

	SECTION("updateLast") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.updateLast(4);

		REQUIRE(list.getLast() == 4);
	}

	SECTION("update") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.update(0, 4);
		list.update(1, 5);
		list.update(2, 6);

		REQUIRE(list.getFirst() == 4);
		REQUIRE(list.get(1) == 5);
		REQUIRE(list.getLast() == 6);
	}

	SECTION("removeFirst") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.removeFirst();

		REQUIRE(list.getFirst() == 2);
		REQUIRE(list.getSize() == 2);

		list.removeFirst();

		REQUIRE(list.getFirst() == 3);
		REQUIRE(list.getSize() == 1);

		list.removeFirst();

		REQUIRE(list.getSize() == 0);
	}

	SECTION("removeLast") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.removeLast();

		REQUIRE(list.getLast() == 2);
		REQUIRE(list.getSize() == 2);

		list.removeLast();

		REQUIRE(list.getLast() == 1);
		REQUIRE(list.getSize() == 1);

		list.removeLast();

		REQUIRE(list.getSize() == 0);
	}

	SECTION("remove") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.remove(1);

		REQUIRE(list.getSize() == 2);

		list.remove(1);

		REQUIRE(list.getSize() == 1);

		list.remove(0);

		REQUIRE(list.getSize() == 0);
	}

	SECTION("reverse") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);
		list.insertLast(4);

		list.reverse();

		REQUIRE(list.get(0) == 4);
		REQUIRE(list.get(1) == 3);
		REQUIRE(list.get(2) == 2);
		REQUIRE(list.get(3) == 1);
	}

	SECTION("traverse") {
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

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
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

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
		LinkedList<int> list;

		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);

		list.clear();

		REQUIRE(list.isEmpty());
	}

	SECTION("isEmpty") {
		LinkedList<int> list;

		REQUIRE(list.isEmpty());

		list.insertLast(1);

		REQUIRE_FALSE(list.isEmpty());
	}

	SECTION("random values") {
		LinkedList<int> list;
		std::vector<int> random;

		for (int i{0}; i < 100; i++) {
			int val = rand() % 1000;
			list.insertLast(val);
			random.push_back(val);
		}

		for (int i{0}; i < 100; i++) {
			REQUIRE(list.get(i) == random[i]);
		}
	}
}
