import LinkedList from "../../src/data_structures/LinkedList";

describe("LinkedList", () => {
	test("getHead", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		expect(list.getHead()).toBe(1);
	});

	test("getTail", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		expect(list.getTail()).toBe(3);
	});

	test("contains", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		expect(list.contains(1)).toBe(true);
		expect(list.contains(4)).toBe(false);
	});

	test("push", () => {
		const list = new LinkedList<number>();
		list.push(1);
		list.push(2);
		list.push(3);
		expect(list.length).toBe(3);
		expect(list.getHead()).toBe(1);
		expect(list.getTail()).toBe(3);
	});

	test("unshift", () => {
		const list = new LinkedList<number>();
		list.unshift(1);
		list.unshift(2);
		list.unshift(3);
		expect(list.length).toBe(3);
		expect(list.getHead()).toBe(3);
		expect(list.getTail()).toBe(1);
	});

	test("set", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		list.set(1, 4);
		expect(list.contains(4)).toBe(true);
	});

	test("forEach", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		const callback = jest.fn();
		list.forEach(callback);
		expect(callback).toHaveBeenCalledTimes(3);
	});

	test("toArray", () => {
		const list = new LinkedList<number>([1, 2, 3]);
		expect(list.toArray()).toEqual([1, 2, 3]);
	});
});
