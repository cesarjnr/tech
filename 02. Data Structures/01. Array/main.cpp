#include <iostream>

using namespace std;

int main() {
  int arr1[5];
  int arr2[5] = {1, 2, 3};
  int sizeOfArr1 = sizeof(arr1) / sizeof(*arr1);
  int sizeOfArr2 = sizeof(arr2) / sizeof(*arr2);

  cout << "Size of Array 1: " << sizeOfArr1 << "\n";
  cout << "First Element of Array 2: " << arr2[0] << "\n";

  for (int i = 0; i < sizeOfArr2; i++) {
    cout << " " << arr2[i] << "\n";
  }

  return 0;
};
