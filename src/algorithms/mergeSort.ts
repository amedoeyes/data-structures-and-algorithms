export default function mergeSort(array: number[]): number[] {
	if (array.length <= 1) return array;

	const middle = Math.floor(array.length / 2);
	const left = array.slice(0, middle);
	const right = array.slice(middle);

	return merge(mergeSort(left), mergeSort(right));
}

function merge(left: number[], right: number[]): number[] {
	const sortedArray = [];
	let leftIndex = 0;
	let rightIndex = 0;

	while (leftIndex < left.length && rightIndex < right.length) {
		if (left[leftIndex] <= right[rightIndex]) {
			sortedArray.push(left[leftIndex]);
			leftIndex++;
		}

		if (right[rightIndex] <= left[leftIndex]) {
			sortedArray.push(right[rightIndex]);
			rightIndex++;
		}
	}

	while (leftIndex < left.length) {
		sortedArray.push(left[leftIndex]);
		leftIndex++;
	}

	while (rightIndex < right.length) {
		sortedArray.push(right[rightIndex]);
		rightIndex++;
	}

	return sortedArray;
}
