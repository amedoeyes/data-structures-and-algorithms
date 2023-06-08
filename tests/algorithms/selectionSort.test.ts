import selectionSort from "../../src/algorithms/selectionSort";

describe("Selection Sort", () => {
	test("[5, 2, 4, 6, 1, 3] => [1, 2, 3, 4, 5, 6]", () => {
		expect(selectionSort([5, 2, 4, 6, 1, 3])).toEqual([1, 2, 3, 4, 5, 6]);
	});

	test("[31, 41, 59, 26, 41, 58] => [26, 31, 41, 41, 58, 59,]", () => {
		expect(selectionSort([31, 41, 59, 26, 41, 58])).toEqual([26, 31, 41, 41, 58, 59]);
	});

	test("[5, 2, 4, 6, 1, 3] => [6, 5, 4, 3, 2, 1]", () => {
		expect(selectionSort([5, 2, 4, 6, 1, 3], { order: "desc" })).toEqual([6, 5, 4, 3, 2, 1]);
	});

	test("[31, 41, 59, 26, 41, 58] => [59, 58, 41, 41, 31, 26]", () => {
		expect(selectionSort([31, 41, 59, 26, 41, 58], { order: "desc" })).toEqual([59, 58, 41, 41, 31, 26]);
	});
});
