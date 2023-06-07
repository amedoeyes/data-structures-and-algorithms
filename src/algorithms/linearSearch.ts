export default function linearSearch<T>(array: T[], value: number): number | null {
	let indexOfValue = null;

	for (let index = 0; index < array.length; index++) {
		if (array[index] === value) indexOfValue = index;
	}

	return indexOfValue;
}
