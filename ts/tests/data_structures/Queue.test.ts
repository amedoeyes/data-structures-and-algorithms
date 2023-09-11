import Queue from "../../src/data_structures/Queue";

describe("Queue", () => {
	let queue: Queue<number>;

	beforeEach(() => {
		queue = new Queue();
	});

	test("size", () => {
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		expect(queue.size()).toBe(3);
	});

	test("enqueue", () => {
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		expect(queue.size()).toBe(3);
	});

	test("dequeue", () => {
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		expect(queue.dequeue()).toBe(1);
	});

	test("peek", () => {
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		expect(queue.peek()).toBe(1);
	});

	test("clear", () => {
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);

		queue.clear();

		expect(queue.size()).toBe(0);
	});

	test("isEmpty", () => {
		expect(queue.isEmpty()).toBe(true);

		queue.enqueue(1);

		expect(queue.isEmpty()).toBe(false);
	});
});
