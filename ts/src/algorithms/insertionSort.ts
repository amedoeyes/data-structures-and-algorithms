export default function insertionSort<T>(array: T[]): T[] {
	for (let i = 0; i < array.length; i++) {
		let j = i;

		while (j > 0 && array[j] < array[j - 1]) {
			[array[j - 1], array[j]] = [array[j], array[j - 1]];
			j--;
		}
	}

	return array;
}
