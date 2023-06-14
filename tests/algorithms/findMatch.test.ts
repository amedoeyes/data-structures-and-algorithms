import findMatch from "../../src/algorithms/findMatch";

describe("Find Match", () => {
	test("abc", () => {
		expect(findMatch("abc", "aabbabc")).toBe(4);
		expect(findMatch("abc", "acb")).toBe(-1);
	});
});
