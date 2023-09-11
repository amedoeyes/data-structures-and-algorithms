export default class Queue<T> {
	private data: T[];

	constructor() {
		this.data = [];
	}

	enqueue(item: T) {
		this.data.push(item);
	}

	dequeue(): T | undefined {
		return this.data.shift();
	}

	peek(): T | undefined {
		return this.data[0];
	}

	clear(): void {
		this.data = [];
	}

	isEmpty(): boolean {
		return this.data.length === 0;
	}

	size(): number {
		return this.data.length;
	}
}
