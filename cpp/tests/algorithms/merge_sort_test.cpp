#include "algorithms/merge_sort.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Merge Sort") {
	SECTION("int") {
		std::vector<int> vector{5, 7, 9, 2, 4, 6, 8, 10, 3, 1};

		mergeSort(vector);

		REQUIRE(vector == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
	}

	SECTION("std::string") {
		std::vector<std::string> vector{"orange", "banana", "apple", "pear"};

		mergeSort(vector);

		REQUIRE(
			vector ==
			std::vector<std::string>{"apple", "banana", "orange", "pear"}
		);
	}

	SECTION("char") {
		std::vector<char> vector{'s', 'a', 'l', '5', 'e', 'c',
								 '4', 'a', 't', 'r', '2'};

		mergeSort(vector);

		REQUIRE(
			vector ==
			std::vector<char>{'2', '4', '5', 'a', 'a', 'c', 'e', 'l', 'r', 's', 't'}
		);
	}
}
