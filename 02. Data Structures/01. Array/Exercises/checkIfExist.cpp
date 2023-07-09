#include <vector>
#include <iostream>

using namespace std;

bool checkIfExist(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  vector<int> firstInput {10,2,5,3};
  vector<int> secondInput {7,1,14,11};
  vector<int> thirdInput {3,1,7,11};

  cout << "Output: " << checkIfExist(firstInput) << "\n";
  cout << "Output: " << checkIfExist(secondInput) << "\n";
  cout << "Output: " << checkIfExist(thirdInput) << "\n";

  return 0;
}
