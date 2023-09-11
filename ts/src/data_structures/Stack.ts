export default class Stack<T> {
	private data: T[];

	constructor() {
		this.data = [];
	}

	push(item: T) {
		this.data.push(item);
	}

	pop(): T | undefined {
		return this.data.pop();
	}

	peek(): T | undefined {
		return this.data[this.data.length - 1];
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
