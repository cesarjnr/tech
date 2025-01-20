#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *prev, *next;
};

class DoublyLinkedList {
  private:
    Node *head;

  public:
    DoublyLinkedList() {
      head = nullptr;
    }

    Node *insert(int data, Node *afterNode) {
      Node *newNode = new Node;
      newNode->data = data;

      if (afterNode == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
      } else {
        newNode->prev = afterNode;
        newNode->next = afterNode->next;

        if (afterNode->next != nullptr) {
          afterNode->next->prev = newNode;
          afterNode->next = newNode;
        } else {
          afterNode->next = newNode;
        }
      }

      return newNode;
    }

    void remove(Node *node) {
      if (node != nullptr) {
        if (node == head) {
          head = head->next;
          head->prev = nullptr;
        } else {
          node->prev->next = node->next;

          if (node->next != nullptr) {
            node->next->prev = node->prev;
          }

          delete node;
        }
      }
    }
    
    void traverse() {
      Node *currentNode = head;

      while (currentNode != nullptr) {
        cout << "Current Node Value: " << currentNode->data << "\n";

        currentNode = currentNode->next;
      }
      
    }
};
