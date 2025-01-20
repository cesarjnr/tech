#include <iostream>
#include <iomanip>
#include "stack.cpp"

using namespace std;

int main() {
  Stack stack;

  cout << "Is stack empty? " << std::boolalpha << stack.empty() << "\n";
  
  stack.push(1);
  cout << "After pushing 1..." << "\n";
  stack.display();

  stack.push(2);
  cout << "After pushing 2..." << "\n";
  stack.display();

  stack.pop();
  cout << "After popping 2..." << "\n";
  stack.display();

  stack.push(3);
  cout << "After pushing 3..." << "\n";
  stack.display();

  cout << "Is stack empty? " << std::boolalpha << stack.empty() << "\n";

  cout << "Top value: " << stack.top() << "\n";

  return 0;
}