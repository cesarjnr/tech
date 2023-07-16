#include <iostream>

#define ARRAY_SIZE 100

using namespace std;

class Stack {
  private:
    int topIndex;
    int stackArray[ARRAY_SIZE];

  public:
    Stack() {
      topIndex = -1;
    }

    void push(int data) {
      if (topIndex >= (ARRAY_SIZE - 1)) {
        cout << "Stack overflow";
      } else {
        stackArray[++topIndex] = data;
      }
    }

    void pop() {
      if (topIndex != -1) {
        topIndex--;
      } else {
        cout << "Stack is empty";
      }
    }

    int top() {
      if (topIndex != -1) {
        return stackArray[topIndex];
      } else {
        throw std::runtime_error("Stack is empty. Cannot get top element.");
      }
    }

    bool empty() {
      return topIndex == -1;
    }

    void display() {
      if (topIndex != -1) {
        for (int i = topIndex; i >= 0 ; i--) {
          cout << stackArray[i] << "\n";
        }
      }
    }
};
