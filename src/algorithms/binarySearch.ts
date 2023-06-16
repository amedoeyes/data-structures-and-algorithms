export default function binarySearch(array: number[], target: number): number {
	let low = 0;
	let high = array.length - 1;

	while (low <= high) {
		const mid = Math.floor((low + high) / 2);

		if (array[mid] < target) low = mid + 1;
		else if (array[mid] > target) high = mid - 1;
		else return mid;
	}

	return -1;
}
