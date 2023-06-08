type Options = { order?: "asc" | "desc" };

export default function selectionSort(array: number[], options: Options = { order: "asc" }): number[] {
	const isAsc = options.order === "asc";

	for (let currentIndex = 0; currentIndex < array.length; currentIndex++) {
		const currentValue = array[currentIndex];
		let extremeIndex = currentIndex;

		for (let searchIndex = currentIndex; searchIndex < array.length; searchIndex++) {
			if (isAsc ? array[searchIndex] < array[extremeIndex] : array[searchIndex] > array[extremeIndex]) {
				extremeIndex = searchIndex;
			}
		}

		array[currentIndex] = array[extremeIndex];
		array[extremeIndex] = currentValue;
	}

	return array;
}
