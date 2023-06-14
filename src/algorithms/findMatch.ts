export default function findMatch(pattern: string, text: string) {
	for (let i = 0; i < text.length; i++) {
		let j = 0;

		while (pattern[j] === text[i + j] && j < pattern.length) j++;

		if (j === pattern.length) return i;
	}

	return -1;
}
