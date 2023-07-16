#include <iostream>
#include <iomanip>
#include "stack.cpp"

using namespace std;

int main() {
  Stack stack(1);
  cout << "After initializing with value 1..." << "\n";
  stack.display();

  stack.pop();
  cout << "After popping 1..." << "\n";
  stack.display();

  cout << "Is stack empty? " << std::boolalpha << stack.empty() << "\n";

  stack.push(2);
  cout << "After pushing 2..." << "\n";
  stack.display();

  stack.push(5);
  cout << "After pushing 5..." << "\n";
  stack.display();

  stack.pop();
  cout << "After popping 10..." << "\n";
  stack.display();

  stack.push(2);
  cout << "After pushing 2..." << "\n";
  stack.display();

  cout << "Is stack empty? " << std::boolalpha << stack.empty() << "\n";

  cout << "Top value: " << stack.top() << "\n";

  return 0;
};
