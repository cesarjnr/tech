#include "singlyList.cpp"

int main() {
  LinkedList linkedList;

  Node *firstNodeInserted = linkedList.insert(1, nullptr);
  Node *secondNodeInserted = linkedList.insert(3, firstNodeInserted);
  Node *thirdNodeInserted = linkedList.insert(2, firstNodeInserted);
  
  linkedList.traverse();
  linkedList.remove(nullptr);
  linkedList.traverse();
  linkedList.remove(thirdNodeInserted);
  linkedList.traverse();
}
