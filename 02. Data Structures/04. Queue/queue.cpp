#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

class Queue {
  private:
    Node *head;
    Node *tail;

  public:
    Queue() {
      head = nullptr;
      tail = nullptr;
    };

    void enqueue(int data) {
      Node *new_node = new Node;

      new_node->data = data;

      if (head == nullptr && tail == nullptr) {
        head = new_node;
      } else {
        tail->next = new_node;
      }

      tail = new_node;
    };

    int dequeue() {
      if (head == nullptr) {
        throw "Queue is empty!";
      } else {
        struct Node *old_head = head;
        int old_head_data = head->data;
        head = old_head->next;

        if (old_head == tail) {
          delete tail;
        }

        delete old_head;

        return old_head_data;
      }
    };

    void display() {
      struct Node *current_node = head;

      while (current_node != nullptr) {
        cout << current_node->data << "\n";

        current_node = current_node->next;
      }
      
    };
};
