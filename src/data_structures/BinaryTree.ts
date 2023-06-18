class Node<T> {
	value: T;
	parent: Node<T> | null;
	left: Node<T> | null;
	right: Node<T> | null;

	constructor(value: T) {
		this.value = value;
		this.parent = null;
		this.left = null;
		this.right = null;
	}

	height(): number {
		if (!this.left && !this.right) return 0;

		const leftHeight = this.left ? this.left.height() : 0;
		const rightHeight = this.right ? this.right.height() : 0;

		return Math.max(leftHeight, rightHeight) + 1;
	}

	min(): Node<T> {
		if (!this.left) return this;

		return this.left.min();
	}

	max(): Node<T> {
		if (!this.right) return this;

		return this.right.max();
	}

	search(value: T): Node<T> | null {
		if (this.value === value) return this;
		if (value < this.value && this.left) return this.left.search(value);
		if (value > this.value && this.right) return this.right.search(value);

		return null;
	}

	insert(value: T): void {
		if (value < this.value) {
			if (!this.left) {
				this.left = new Node<T>(value);
				this.left.parent = this;

				return;
			}

			this.left.insert(value);
		}

		if (value > this.value) {
			if (!this.right) {
				this.right = new Node<T>(value);
				this.right.parent = this;

				return;
			}

			this.right.insert(value);
		}
	}

	delete(): void {
		if (!this.left && !this.right) {
			if (this.parent?.left === this) this.parent.left = null;
			if (this.parent?.right === this) this.parent.right = null;
		}

		if (this.left && !this.right) {
			this.left.parent = this.parent;

			if (this.parent?.left === this) this.parent.left = this.left;
			if (this.parent?.right === this) this.parent.right = this.left;
		}

		if (!this.left && this.right) {
			this.right.parent = this.parent;

			if (this.parent?.left === this) this.parent.left = this.right;
			if (this.parent?.right === this) this.parent.right = this.right;
		}

		if (this.left && this.right) {
			const min = this.right.min();

			if (min.parent?.left === min) min.parent.left = null;

			if (min.parent?.right === min) min.parent.right = null;

			min.parent = this.parent;
			min.left = this.left;
			min.right = this.right;

			if (this.right) this.right.parent = min;
			if (this.left) this.left.parent = min;

			if (this.parent?.left === this) this.parent.left = min;
			if (this.parent?.right === this) this.parent.right = min;
		}
	}

	traverse(callback: (node: Node<T>) => void): void {
		if (this.left) this.left.traverse(callback);
		callback(this);
		if (this.right) this.right.traverse(callback);
	}

	toArray(): T[] {
		const array: T[] = [];

		if (this.left) array.push(...this.left.toArray());
		array.push(this.value);
		if (this.right) array.push(...this.right.toArray());

		return array;
	}
}

export default class BinaryTree<T> {
	private root: Node<T> | null;

	constructor() {
		this.root = null;
	}

	height(): number {
		if (!this.root) return 0;

		return this.root.height();
	}

	min(): Node<T> | null {
		if (!this.root) return null;

		return this.root.min();
	}

	max(): Node<T> | null {
		if (!this.root) return null;

		return this.root.max();
	}

	search(value: T): Node<T> | null {
		if (!this.root) return null;

		return this.root.search(value);
	}

	insert(value: T): void {
		if (!this.root) {
			this.root = new Node<T>(value);

			return;
		}

		this.root.insert(value);
	}

	delete(value: T): void {
		const node = this.search(value);

		if (!node) return;

		if (node === this.root) {
			if (!this.root.left && !this.root.right) this.root = null;

			if (this.root?.left && !this.root.right) {
				this.root.left.parent = null;
				this.root = this.root.left;
			}

			if (!this.root?.left && this.root?.right) {
				this.root.right.parent = null;
				this.root = this.root.right;
			}

			if (this.root?.left && this.root?.right) {
				const min = this.root.right.min();

				if (min.parent?.left === min) min.parent.left = null;
				if (min.parent?.right === min) min.parent.right = null;

				min.parent = null;
				min.left = this.root.left;
				min.right = this.root.right;

				if (this.root.left) this.root.left.parent = min;
				if (this.root.right) this.root.right.parent = min;

				this.root = min;
			}

			return;
		}

		node.delete();
	}

	traverse(callback: (node: Node<T>) => void): void {
		if (!this.root) return;

		this.root.traverse(callback);
	}

	isEmpty(): boolean {
		return !this.root;
	}

	toArray(): T[] {
		if (!this.root) return [];

		return this.root.toArray();
	}
}
