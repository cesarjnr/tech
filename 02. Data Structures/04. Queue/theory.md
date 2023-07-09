### 1. Definitions

A queue is a linear data structure which models real world queues by having two primary operations, namely **enqueue** and **dequeue**.

### 2. Terminology

* **Enqueue / Adding / Offering**: process of adding an element to the back of the queue
* **Dequeue / Polling**: process of removing an element from the front of the queue

### 3. Usage

* Model a real word queue
* Web server request management on a first-come, first-served basis
* Breadth first search (BFS) graph traversal

### 3. Complexity

| Operation | Complexity | Why                                                         |
| :--------:| :---------:| :-----------------------------------------------------------|
| Enqueue   | O(1)       | Because we have a pointer to the back of the queue          | 
| Dequeue   | O(1)       | Because we have a pointer to the front of the queue         |
| Peeking   | O(1)       | Because we have a pointer to the front of the queue         |
| Contains  | O(n)       | Because we might have to scan all the elements in the queue |
| Removal   | O(n)       | Because we might have to scan all the elements in the queue |
