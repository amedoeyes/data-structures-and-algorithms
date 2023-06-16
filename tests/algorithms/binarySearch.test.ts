import binarySearch from "../../src/algorithms/binarySearch";

describe("Binary Search", () => {
	test("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 5", () => {
		expect(binarySearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5)).toBe(4);
	});

	test("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 10", () => {
		expect(binarySearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 10)).toBe(9);
	});

	test("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 1", () => {
		expect(binarySearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 1)).toBe(0);
	});
});
