#include <iostream>

using namespace std;

void printList(Node* head) {
  cout << "[";

  if (head != nullptr) {
    while (head != nullptr) {
      cout << head->data;

      if (head->next != nullptr) {
        cout << ",";
      }

      head = head->next;
    }
  }

  cout << "]" << "\n";
}
