class Node<T> {
	data: T;
	next: Node<T> | null;
	prev: Node<T> | null;

	constructor(data: T) {
		this.data = data;
		this.next = null;
		this.prev = null;
	}
}

export default class LinkedList<T> {
	private head: Node<T> | null;
	private tail: Node<T> | null;
	length: number;

	constructor(initialArray?: T[]) {
		this.head = null;
		this.tail = null;
		this.length = 0;

		if (initialArray) {
			for (let i = 0; i < initialArray.length; i++) {
				this.push(initialArray[i]);
			}
		}
	}

	private getNode(data: T): Node<T> | null {
		let currentNode = this.head;

		while (currentNode) {
			if (currentNode.data === data) break;
			currentNode = currentNode.next;
		}

		return currentNode;
	}

	unshift(data: T): T {
		const newNode = new Node(data);

		if (this.head) {
			newNode.next = this.head;

			this.head.prev = newNode;
			this.head = newNode;
			this.length++;

			return data;
		}

		this.head = newNode;
		this.tail = newNode;
		this.length++;

		return data;
	}

	push(data: T): T {
		const newNode = new Node(data);

		if (this.tail) {
			newNode.prev = this.tail;

			this.tail.next = newNode;
			this.tail = newNode;
			this.length++;

			return data;
		}

		this.head = newNode;
		this.tail = newNode;
		this.length++;

		return data;
	}

	shift(): T | null {
		const data = this.head?.data || null;

		if (this.head && this.head.next) {
			this.head = this.head.next;
			this.head.prev = null;
			this.length--;

			return data;
		}

		this.head = null;
		this.tail = null;
		this.length--;

		return data;
	}

	pop(): T | null {
		const data = this.tail?.data || null;

		if (this.tail && this.tail.prev) {
			this.tail = this.tail.prev;
			this.tail.next = null;
			this.length--;

			return data;
		}

		this.head = null;
		this.tail = null;
		this.length--;

		return data;
	}

	remove(data: T): T | null {
		const currentNode = this.getNode(data);
		const currentNodeData = currentNode?.data || null;

		if (currentNode === this.head) return this.shift();
		if (currentNode === this.tail) return this.pop();

		if (currentNode && currentNode.prev) {
			currentNode.prev.next = currentNode.next;
			this.length--;
		}

		return currentNodeData;
	}

	set(data: T, newData: T): T | null {
		const currentNode = this.getNode(data);

		if (currentNode) {
			currentNode.data = newData;
		}

		return currentNode?.data || null;
	}

	getHead(): T | null {
		return this.head?.data || null;
	}

	getTail(): T | null {
		return this.tail?.data || null;
	}

	contains(data: T): boolean {
		return this.getNode(data) !== null;
	}

	forEach(callback: (data: T) => void) {
		let currentNode = this.head;

		while (currentNode) {
			callback(currentNode.data);
			currentNode = currentNode.next;
		}
	}

	toArray(): T[] {
		const array: T[] = [];
		let currentNode = this.head;

		while (currentNode) {
			array.push(currentNode.data);
			currentNode = currentNode.next;
		}

		return array;
	}

	[Symbol.iterator](): Iterator<T> {
		let currentNode = this.head;

		return {
			next() {
				if (!currentNode) return { value: null, done: true };

				const value = currentNode.data;
				currentNode = currentNode.next;

				return {
					value: value,
					done: false,
				};
			},
		};
	}
}
