#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int>& elements) {
  cout << "[";

  for (auto i = elements.begin(); i != elements.end(); i++) {
    cout << *i;

    if (i + 1 == elements.end()) {
      cout << "]" << "\n";
    } else {
      cout << ",";
    }
  }
}
