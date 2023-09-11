import insertionSort from "../../src/algorithms/insertionSort";

describe("Insertion Sort", () => {
	test("[5, 2, 4, 6, 1, 3] => [1, 2, 3, 4, 5, 6]", () => {
		expect(insertionSort([5, 2, 4, 6, 1, 3])).toEqual([1, 2, 3, 4, 5, 6]);
	});

	test("[I, N, S, E, R, T, I, O, N] => [E, I, I, N, N, O, R, S, T]", () => {
		expect(insertionSort(["I", "N", "S", "E", "R", "T", "I", "O", "N"])).toEqual([
			"E",
			"I",
			"I",
			"N",
			"N",
			"O",
			"R",
			"S",
			"T",
		]);
	});
});
