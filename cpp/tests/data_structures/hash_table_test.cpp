#include "data_structures/hash_table.hpp"

#include <iostream>
#include <string>

#include "catch2/catch_test_macros.hpp"

TEST_CASE("HashTable", "[HashTable]") {
	SECTION("[]") {
		HashTable<int, int> table;

		table[1] = 1;
		table[2] = 2;
		table[3] = 3;

		REQUIRE(table[1] == 1);
		REQUIRE(table[2] == 2);
		REQUIRE(table[3] == 3);
	}

	SECTION("set") {
		HashTable<int, int> table;

		table.set(1, 1);
		table.set(2, 2);
		table.set(1, 3);

		REQUIRE(table.get(1) == 3);
		REQUIRE(table.get(2) == 2);
	}

	SECTION("get") {
		HashTable<int, int> table;

		table.set(1, 1);
		table.set(2, 2);
		table.set(3, 3);

		REQUIRE(table.get(1) == 1);
		REQUIRE(table.get(2) == 2);
		REQUIRE(table.get(3) == 3);

		REQUIRE_THROWS(table.get(4));
	}

	SECTION("resize") {
		HashTable<int, int> table;

		for (int i = 0; i < 20; ++i) {
			table.set(i, i);
		}

		for (int i = 0; i < 20; ++i) {
			REQUIRE(table.get(i) == i);
		}
	}

	SECTION("clear") {
		HashTable<int, int> table;

		table.set(1, 1);
		table.set(2, 2);

		table.clear();

		REQUIRE_THROWS(table.get(1));
		REQUIRE_THROWS(table.get(2));
	}

}
