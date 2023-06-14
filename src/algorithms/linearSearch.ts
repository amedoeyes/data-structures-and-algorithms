export default function linearSearch<T>(array: T[], value: number): number | null {
	let indexOfValue = null;

	for (let currentIndex = 0; currentIndex < array.length; currentIndex++) {
		if (array[currentIndex] === value) indexOfValue = currentIndex;
	}

	return indexOfValue;
}
