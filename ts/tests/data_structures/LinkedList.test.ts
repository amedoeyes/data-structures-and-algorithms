import LinkedList from "../../src/data_structures/LinkedList";

describe("LinkedList", () => {
	let list: LinkedList<number>;

	beforeEach(() => {
		list = new LinkedList([1, 2, 3]);
	});

	test("getHead", () => {
		expect(list.getHead()).toBe(1);
	});

	test("getTail", () => {
		expect(list.getTail()).toBe(3);
	});

	test("contains", () => {
		expect(list.contains(1)).toBe(true);
		expect(list.contains(4)).toBe(false);
	});

	test("push", () => {
		expect(list.push(4)).toBe(4);
		expect(list.contains(4)).toBe(true);
		expect(list.getTail()).toBe(4);
		expect(list.length).toBe(4);
	});

	test("unshift", () => {
		expect(list.unshift(4)).toBe(4);
		expect(list.contains(4)).toBe(true);
		expect(list.getHead()).toBe(4);
		expect(list.length).toBe(4);
	});

	test("set", () => {
		list.set(1, 4);

		expect(list.contains(4)).toBe(true);
	});

	test("pop", () => {
		expect(list.pop()).toBe(3);
		expect(list.contains(3)).toBe(false);
		expect(list.getTail()).toBe(2);
		expect(list.length).toBe(2);
	});

	test("shift", () => {
		expect(list.shift()).toBe(1);
		expect(list.contains(1)).toBe(false);
		expect(list.getHead()).toBe(2);
		expect(list.length).toBe(2);
	});

	test("remove", () => {
		expect(list.remove(1)).toBe(1);
		expect(list.contains(1)).toBe(false);
		expect(list.getHead()).toBe(2);
		expect(list.length).toBe(2);
	});

	test("forEach", () => {
		const callback = jest.fn();

		list.forEach(callback);

		expect(callback).toHaveBeenCalledTimes(3);
	});

	test("toArray", () => {
		expect(list.toArray()).toEqual([1, 2, 3]);
	});
});
