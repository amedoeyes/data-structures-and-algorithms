import BinaryTree from "../../src/data_structures/BinaryTree";

describe("BinaryTree", () => {
	let tree: BinaryTree<number>;

	beforeEach(() => {
		tree = new BinaryTree<number>();

		tree.insert(5);
		tree.insert(3);
		tree.insert(7);
	});

	test("height", () => {
		expect(tree.height()).toBe(1);
	});

	test("min", () => {
		expect(tree.min()?.value).toBe(3);
	});

	test("max", () => {
		expect(tree.max()?.value).toBe(7);
	});

	test("insert", () => {
		expect(tree.toArray()).toEqual([3, 5, 7]);
	});

	test("delete", () => {
		tree.delete(5);

		expect(tree.toArray()).toEqual([3, 7]);
	});

	test("search", () => {
		expect(tree.search(5)?.value).toBe(5);
	});

	test("traverse", () => {
		const fn = jest.fn();
		let sum = 0;

		tree.traverse(fn);
		tree.traverse((node) => {
			sum += node.value;
		});

		expect(fn).toHaveBeenCalledTimes(3);
		expect(sum).toBe(15);
	});

	test("isEmpty", () => {
		expect(tree.isEmpty()).toBe(false);
	});

	test("toArray", () => {
		expect(tree.toArray()).toEqual([3, 5, 7]);
	});
});
