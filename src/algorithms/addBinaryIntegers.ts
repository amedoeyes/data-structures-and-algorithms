export default function addBinaryIntegers(array1: number[], array2: number[]): number[] {
	const length = Math.max(array1.length, array2.length);
	const result = Array(length + 1).fill(0);
	let carry = 0;

	for (let i = length - 1; i >= 0; i--) {
		const bit1 = array1[i] || 0;
		const bit2 = array2[i] || 0;
		const sum = bit1 + bit2 + carry;

		result[i + 1] = sum % 2;
		carry = Math.floor(sum / 2);
	}

	result[0] = carry;

	return result;
}
