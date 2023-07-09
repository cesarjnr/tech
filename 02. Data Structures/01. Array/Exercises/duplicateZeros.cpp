#include <vector>
#include <iostream>
#include "printVector.cpp"

using namespace std;

vector<int> duplicateZeros(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++){
    if (arr[i] == 0 && i != arr.size() - 1) {
      for (int j = arr.size() - 1; j > i; j--) {
        if (j + 1 < arr.size()) {
          arr[j + 1] = arr[j];
        }
      }

      arr[i + 1] = 0;
      i++;
    }
  }

  return arr;
}

int main() {
  vector<int> firstInput {1,0,2,3,0,4,5,0};
  vector<int> secondInput {1,2,3};

  vector<int> firstResult = duplicateZeros(firstInput);
  cout << "Output: ";
  printVector(firstResult);

  vector<int> secondResult = duplicateZeros(secondInput);
  cout << "Output: ";
  printVector(secondResult);

  return 0;
}
