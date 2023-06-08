# Data Structures and Algorithms

This repository contains a collection of data structures and algorithms I have written.

## Usage

## Data Structures

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

## Algorithms

### Insertion Sort

O(n^2)

```typescript
 insertionSort([5, 2, 4, 6, 1, 3]); // [1, 2, 3, 4, 5, 6]
 insertionSort([5, 2, 4, 6, 1, 3], { order: "asc" }); // [6, 5, 4, 3, 2, 1]
```

### Sum Array

O(n)

```typescript
sumArray([1, 2, 3]); // 6
```

### Linear Search

O(n)

```typescript
 linearSearch([5, 2, 4, 6, 1, 3], 5); // 0
 linearSearch([5, 2, 4, 6, 1, 3], 6); // 3
```

### Add Binary Integers

O(n)

```typescript
addBinaryIntegers([1, 0, 1], [1, 0, 0]); // [1, 0, 0, 1]
```

### Selection Sort

O(n)

```typescript
selectionSort([5, 2, 4, 6, 1, 3], { order: "asc" }); // [6, 5, 4, 3, 2, 1]
```

selectionSort([5, 2, 4, 6, 1, 3]); // [1, 2, 3, 4, 5, 6]

### Merge Sort

O(n log n)

```typescript
mergeSort([5, 2, 4, 6, 1, 3]); // [1, 2, 3, 4, 5, 6]

```
