export default class PriorityQueue<T> {
	private data: [T, number][];

	constructor() {
		this.data = [];
	}

	enqueue(value: T, priority: number) {
		this.data.push([value, priority]);
		this.data.sort((a, b) => a[1] - b[1]);
	}

	dequeue() {
		const value = this.data[0][0];

		this.data.shift();

		return value;
	}

	peek() {
		return this.data[0][0];
	}

	clear() {
		this.data = [];
	}

	isEmpty() {
		return this.data.length === 0;
	}

	size() {
		return this.data.length;
	}
}
