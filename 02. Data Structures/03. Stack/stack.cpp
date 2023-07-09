#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class Stack {
  private:
    Node *top = nullptr;

  public:
    void push(int data) {
      Node *newNode = new Node;
      newNode->data = data;
      newNode->next = nullptr;
      top->next = newNode;
      top = newNode;
    };

    void pop() {
      if (top != nullptr) {
        struct Node *nodeToBeRemoved = top;

        top = nodeToBeRemoved->next;

        delete nodeToBeRemoved;
      }
    };

    void display() {
      struct Node *currentNode = top;

      while (currentNode != nullptr) {
        cout << currentNode->data << "\n";

        currentNode = currentNode->next;
      }
    };
};
