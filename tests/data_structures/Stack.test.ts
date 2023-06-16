import Stack from "../../src/data_structures/Stack";

describe("Stack", () => {
	let stack: Stack<number>;

	beforeEach(() => {
		stack = new Stack();
	});

	test("size", () => {
		stack.push(1);
		stack.push(2);
		stack.push(3);

		expect(stack.size()).toBe(3);
	});

	test("push", () => {
		stack.push(1);
		stack.push(2);
		stack.push(3);

		expect(stack.size()).toBe(3);
	});

	test("pop", () => {
		stack.push(1);
		stack.push(2);
		stack.push(3);

		expect(stack.pop()).toBe(3);
		expect(stack.size()).toBe(2);
	});

	test("peek", () => {
		stack.push(1);
		stack.push(2);
		stack.push(3);

		expect(stack.peek()).toBe(3);
	});

	test("clear", () => {
		stack.push(1);
		stack.push(2);
		stack.push(3);

		stack.clear();

		expect(stack.size()).toBe(0);
	});

	test("isEmpty", () => {
		expect(stack.isEmpty()).toBe(true);

		stack.push(1);

		expect(stack.isEmpty()).toBe(false);
	});
});
