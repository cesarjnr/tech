#include <iostream>
#include "../Singly List/singlyList.cpp"
#include "printList.cpp"

using namespace std;

Node* reverseList(Node* head) {
  Node* newHead = head;

  if (head != nullptr) {
    while (head->next != nullptr) {
      Node* previousHead = newHead;

      newHead = head->next;
      head->next = newHead->next;
      newHead->next = previousHead;
    }
  }

  return newHead;
}

int main() {
  LinkedList firstList;
  Node* firstListHead = firstList.insert(1, nullptr);
  Node* firstListSecondNode = firstList.insert(2, firstListHead);
  Node* firstListThirdNode = firstList.insert(3, firstListSecondNode);
  Node* firstListFourthNode = firstList.insert(4, firstListThirdNode);
  Node* firstListFifthNode = firstList.insert(5, firstListFourthNode);

  cout << "Input: ";
  printList(firstListHead);
  cout << "Output: ";
  Node* firstListNewHead = reverseList(firstListHead);
  printList(firstListNewHead);

  LinkedList secondList;
  Node* secondListHead = secondList.insert(1, nullptr);
  Node* secondListSecondNode = secondList.insert(2, secondListHead);

  cout << "Input: ";
  printList(secondListHead);
  cout << "Output: ";
  Node* secondListNewHead = reverseList(secondListHead);
  printList(secondListNewHead);

  Node* thirdListHead = nullptr;

  cout << "Input: ";
  printList(thirdListHead);
  cout << "Output: ";
  Node* thirdListNewHead = reverseList(thirdListHead);
  printList(thirdListNewHead);
}
