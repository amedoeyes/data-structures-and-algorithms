export default function insertionSort<T>(array: T[]): T[] {
	for (let index = 0; index < array.length; index++) {
		let sortIndex = index;

		while (sortIndex > 0 && array[sortIndex] < array[sortIndex - 1]) {
			[array[sortIndex - 1], array[sortIndex]] = [array[sortIndex], array[sortIndex - 1]];
			sortIndex--;
		}
	}

	return array;
}
