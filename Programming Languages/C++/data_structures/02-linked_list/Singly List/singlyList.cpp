#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class LinkedList {
  private:
    Node *head;

  public:
    LinkedList() {
      head = nullptr;
    }

    Node *insert(int data, Node *afterNode) {
      Node *newNode = new Node;

      newNode->data = data;

      if (afterNode == nullptr) {
        newNode->next = head;
        head = newNode;
      } else {
        newNode->next = afterNode->next;
        afterNode->next = newNode;
      }

      return newNode;
    }

    void remove(Node *afterNode) {
      if (afterNode == nullptr) {
        if (head != nullptr) {
          head = head->next;
        }
      } else {
        Node *nodeToBeDeleted = afterNode->next;
        afterNode->next = nodeToBeDeleted->next;

        delete nodeToBeDeleted;
      }
    }

    void traverse() {
      struct Node *currentNode = head;

      while (currentNode != nullptr) {
        cout << "Current Node Value: " << currentNode->data << "\n";

        currentNode = currentNode->next;
      }
    }
};
