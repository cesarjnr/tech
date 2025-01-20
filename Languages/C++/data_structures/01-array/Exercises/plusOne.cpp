#include <vector>
#include <iostream>
#include "printVector.cpp"

using namespace std;

vector<int> plusOne(vector<int>& digits) {
  for (auto i = digits.rbegin(); i != digits.rend(); i++) {
    if (*i == 9) {
      *i = 0;
    } else {
      *i = *i + 1;
    }

    if (*i != 0) {
      break;
    }
  }

  if (digits[0] == 0) {
    digits.insert(digits.begin(), 1);
  }

  return digits;
}

int main() {
  vector<int> firstInput {1,2,3};
  vector<int> secondInput {4,3,2,1};
  vector<int> thirdInput {9};

  vector<int> firstResult = plusOne(firstInput);
  cout << "Output: ";
  printVector(firstResult);

  vector<int> secondResult = plusOne(secondInput);
  cout << "Output: ";
  printVector(secondResult);

  vector<int> thirdResult = plusOne(thirdInput);
  cout << "Output: ";
  printVector(thirdResult);

  return 0;
}
