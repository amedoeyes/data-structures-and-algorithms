# Data Structures and Algorithms

This repository contains a collection of data structures and algorithms I have written.

## Usage

### Data Structures

### LinkedList

```typescript
const linkedList = new LinkedList([1, 2, 3]);

linkedList.unshift(0); // [0, 1, 2, 3]
linkedList.push(4); // [0, 1, 2, 3, 4]

linkedList.shift(); // [1, 2, 3, 4] 
linkedList.pop(); // [1, 2, 3]
linkedList.remove(2); // [1, 3]

linkedList.set(1, 5); // [5, 3]
linkedList.contains(5); // true

linkedList.toArray(); // [5, 3]

linkedList.forEach(item => console.log(item)); // 5 3
```
