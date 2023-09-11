class Node<K, V> {
	key: K;
	value: V;

	constructor(key: K, value: V) {
		this.key = key;
		this.value = value;
	}
}

export default class HashTable<K, V> {
	private table: Node<K, V>[][];
	private size: number;
	private capacity: number;
	private loadFactor: number;

	constructor(capacity = 10, loadFactor = 0.75) {
		this.table = new Array(capacity);
		this.size = 0;
		this.capacity = capacity;
		this.loadFactor = loadFactor;

		for (let i = 0; i < this.capacity; i++) {
			this.table[i] = [];
		}
	}

	private hash(key: K): number {
		const keyString = String(key);
		let hash = 5381;

		for (let i = 0; i < keyString.length; i++) {
			hash = (hash << 5) + hash + keyString.charCodeAt(i);
		}

		hash = hash >>> 0;

		return hash % this.capacity;
	}

	private resize() {
		this.capacity *= 2;
		const newTable = new Array(this.capacity);

		for (let i = 0; i < newTable.length; i++) {
			newTable[i] = [];
		}

		for (let i = 0; i < this.table.length; i++) {
			if (this.table[i].length === 0) continue;

			for (let j = 0; j < this.table[i].length; j++) {
				const node = this.table[i][j];
				const index = this.hash(node.key);

				newTable[index].push(node);
			}
		}

		this.table = newTable;
	}

	set(key: K, value: V): void {
		if (this.size / this.capacity > this.loadFactor) this.resize();

		const node = new Node(key, value);
		const index = this.hash(key);
		const bucket = this.table[index];

		this.size++;

		for (let i = 0; i < bucket.length; i++) {
			if (bucket[i].key === key) {
				bucket[i].value = value;

				return;
			}
		}

		bucket.push(node);
	}

	get(key: K): V | null {
		const index = this.hash(key);
		const bucket = this.table[index];

		for (let i = 0; i < bucket.length; i++) {
			if (bucket[i].key === key) return bucket[i].value;
		}

		return null;
	}

	remove(key: K): V | null {
		const index = this.hash(key);
		const bucket = this.table[index];

		for (let i = 0; i < bucket.length; i++) {
			const node = bucket[i];

			if (node.key === key) {
				bucket.splice(i, 1);
				this.size--;

				return node.value;
			}
		}

		return null;
	}

	has(key: K): boolean {
		const index = this.hash(key);
		const bucket = this.table[index];

		for (let i = 0; i < bucket.length; i++) {
			if (bucket[i].key === key) return true;
		}

		return false;
	}

	keys(): K[] {
		const keys: K[] = [];

		for (let i = 0; i < this.table.length; i++) {
			if (this.table[i].length === 0) continue;

			for (let j = 0; j < this.table[i].length; j++) {
				keys.push(this.table[i][j].key);
			}
		}

		return keys;
	}

	values(): V[] {
		const values: V[] = [];

		for (let i = 0; i < this.table.length; i++) {
			if (this.table[i].length === 0) continue;

			for (let j = 0; j < this.table[i].length; j++) {
				values.push(this.table[i][j].value);
			}
		}

		return values;
	}
}
