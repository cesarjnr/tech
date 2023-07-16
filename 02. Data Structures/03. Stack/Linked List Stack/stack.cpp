#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class Stack {
  private:
    Node *topElement = nullptr;

  public:
    Stack(int data) {
      Node *newNode = new Node;
      newNode->data = data;
      newNode->next = nullptr;
      topElement = newNode;
    }

    void push(int data) {
      Node *newNode = new Node;
      newNode->data = data;
      newNode->next = topElement;
      topElement = newNode;
    };

    void pop() {
      if (topElement != nullptr) {
        struct Node *nodeToBeRemoved = topElement;

        topElement = nodeToBeRemoved->next;

        delete nodeToBeRemoved;
      }
    };

    int top() {
      if (topElement != nullptr) {
        return topElement->data;
      } else {
        throw std::runtime_error("Stack is empty. Cannot get top element.");
      }
    }

    bool empty() {
      if (topElement == nullptr) {
        return true;
      } else {
        return false;
      }
    }

    void display() {
      struct Node *currentNode = topElement;

      while (currentNode != nullptr) {
        cout << currentNode->data << "\n";

        currentNode = currentNode->next;
      }
    };
};
