import linearSearch from "../../src/algorithms/linearSearch";

describe("Linear Search", () => {
	test("5 in [5, 2, 4, 6, 1, 3]", () => {
		expect(linearSearch([5, 2, 4, 6, 1, 3], 5)).toBe(0);
	});

	test("6 in [5, 2, 4, 6, 1, 3]", () => {
		expect(linearSearch([5, 2, 4, 6, 1, 3], 6)).toBe(3);
	});

	test("10 not in [5, 2, 4, 6, 1, 3]", () => {
		expect(linearSearch([5, 2, 4, 6, 1, 3], 10)).toBe(null);
	});
});
