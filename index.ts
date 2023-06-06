import LinkedList from "./src/data_structures/LinkedList";

const linkedList = new LinkedList([1, 2, 3]);

linkedList.appendAt(1, 4);

linkedList.shift();
linkedList.shift();
linkedList.shift();
linkedList.shift();
linkedList.shift();
linkedList.shift();
linkedList.shift();

console.log(linkedList.toArray());
console.log(linkedList.getHead(), linkedList.getTail());
