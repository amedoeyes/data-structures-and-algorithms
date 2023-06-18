import PriorityQueue from "../../src/data_structures/PriorityQueue";

describe("PriorityQueue", () => {
	let pq: PriorityQueue<number>;

	beforeEach(() => {
		pq = new PriorityQueue();

		pq.enqueue(1, 1);
		pq.enqueue(2, 2);
		pq.enqueue(3, 3);
		pq.enqueue(4, 4);
		pq.enqueue(5, 5);
	});

	test("enqueue", () => {
		pq.enqueue(6, 6);

		expect(pq.size()).toBe(6);
	});

	test("dequeue", () => {
		expect(pq.dequeue()).toBe(1);
	});

	test("peek", () => {
		expect(pq.peek()).toBe(1);
	});

	test("clear", () => {
		pq.clear();

		expect(pq.size()).toBe(0);
	});

	test("isEmpty", () => {
		expect(pq.isEmpty()).toBe(false);

		pq.clear();

		expect(pq.isEmpty()).toBe(true);
	});

	test("size", () => {
		expect(pq.size()).toBe(5);
	});
});
