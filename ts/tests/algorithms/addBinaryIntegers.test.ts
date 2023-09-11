import addBinaryIntegers from "../../src/algorithms/addBinaryIntegers";

describe("Add Binary Integers", () => {
	test("[1, 0, 1] + [1, 0, 0] = [1, 0, 0, 1]", () => {
		expect(addBinaryIntegers([1, 0, 1], [1, 0, 0])).toEqual([1, 0, 0, 1]);
	});

	test("[0] + [0] = [0, 0]", () => {
		expect(addBinaryIntegers([0], [0])).toEqual([0, 0]);
	});

	test("[0] + [1] = [0 ,1]", () => {
		expect(addBinaryIntegers([0], [1])).toEqual([0, 1]);
	});
});
