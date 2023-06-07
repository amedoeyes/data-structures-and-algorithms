import sumArray from "../../src/algorithms/sumArray";

describe("Sum Array", () => {
	test("[1, 2, 3] => 6", () => {
		expect(sumArray([1, 2, 3])).toBe(6);
	});

	test("[1, 2, 3, 4] => 10", () => {
		expect(sumArray([1, 2, 3, 4])).toBe(10);
	});

	test("[10, 100, 1000, 10000] => 11110", () => {
		expect(sumArray([10, 100, 1000, 10000])).toBe(11110);
	});
});
