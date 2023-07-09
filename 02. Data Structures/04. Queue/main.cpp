#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
  Queue queue;
  int dequeued_data;

  queue.enqueue(1);
  cout << "After Enqueue 1..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  queue.enqueue(2);
  cout << "After Enqueue 2..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  queue.enqueue(3);
  cout << "After Enqueue 3..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  dequeued_data = queue.dequeue();
  cout << "Dequeued Value: " << dequeued_data << "\n";;
  cout << "After Dequeue 1..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  dequeued_data = queue.dequeue();
  cout << "Dequeued Value: " << dequeued_data << "\n";;
  cout << "After Dequeue 2..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  queue.enqueue(4);
  cout << "After Enqueue 4..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  queue.enqueue(5);
  cout << "After Enqueue 5..." << "\n";
  queue.display();
  cout << "===================" << "\n";

  return 0;
};
