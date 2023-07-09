#include <iostream>
#include "stack.cpp"

using namespace std;

int main() {
  Stack stack;

  stack.push(1);
  cout << "After Pushing 1..." << "\n";
  stack.display();

  stack.push(5);
  cout << "After Pushing 5..." << "\n";
  stack.display();

  stack.push(10);
  cout << "After Pushing 10..." << "\n";
  stack.display();

  stack.pop();
  cout << "After Popping 10..." << "\n";
  stack.display();

  stack.pop();
  cout << "After Popping 5..." << "\n";
  stack.display();

  stack.push(2);
  cout << "After Pushing 2..." << "\n";
  stack.display();

  stack.push(3);
  cout << "After Pushing 3..." << "\n";
  stack.display();

  return 0;
};
