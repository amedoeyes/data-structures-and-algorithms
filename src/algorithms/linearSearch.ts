export default function linearSearch<T>(array: T[], value: number): number | null {
	let indexOfValue = null;

	for (let i = 0; i < array.length; i++) {
		if (array[i] === value) indexOfValue = i;
	}

	return indexOfValue;
}
