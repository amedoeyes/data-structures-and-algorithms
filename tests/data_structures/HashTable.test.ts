import HashTable from "../../src/data_structures/HashTable";

describe("HashTable", () => {
	let hashTable: HashTable<number, number>;

	beforeEach(() => {
		hashTable = new HashTable();

		for (let i = 0; i < 10; i++) {
			hashTable.set(i, i);
		}
	});

	test("set", () => {
		hashTable.set(101, 101);

		expect(hashTable.get(101)).toBe(101);
		expect(hashTable.has(101)).toBe(true);
	});

	test("get", () => {
		expect(hashTable.get(0)).toBe(0);
	});

	test("has", () => {
		expect(hashTable.has(0)).toBe(true);
	});

	test("remove", () => {
		expect(hashTable.remove(0)).toBe(0);
		expect(hashTable.has(0)).toBe(false);
	});

	test("keys", () => {
		expect(hashTable.keys()).toEqual([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
	});

	test("values", () => {
		expect(hashTable.values()).toEqual([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
	});
});
