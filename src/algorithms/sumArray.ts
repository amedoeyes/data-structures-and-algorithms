export default function sumArray(array: number[]): number {
	let sum = 0;

	for (let currentIndex = 0; currentIndex < array.length; currentIndex++) {
		sum += array[currentIndex];
	}

	return sum;
}
