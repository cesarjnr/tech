#include "doublyList.cpp"

int main() {
  DoublyLinkedList linkedList;
  Node *firstNodeInserted = linkedList.insert(1, nullptr);
  Node *secondNodeInserted = linkedList.insert(3, firstNodeInserted);
  Node *thirdNodeInserted = linkedList.insert(2, firstNodeInserted);

  linkedList.traverse();
  linkedList.remove(firstNodeInserted);
  linkedList.traverse();
  linkedList.remove(thirdNodeInserted);
  linkedList.traverse();

  return 0;
}
