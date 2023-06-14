export default function selectionSort(array: number[]): number[] {
	for (let currentIndex = 0; currentIndex < array.length; currentIndex++) {
		let minIndex = currentIndex;

		for (let searchIndex = currentIndex; searchIndex < array.length; searchIndex++) {
			if (array[searchIndex] < array[minIndex]) minIndex = searchIndex;
		}

		[array[currentIndex], array[minIndex]] = [array[minIndex], array[currentIndex]];
	}

	return array;
}
