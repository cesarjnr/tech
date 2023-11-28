#include <vector>
#include <iostream>
#include "printVector.cpp"

using namespace std;

int removeElement(vector<int>& nums, int val) {
  for (auto i = nums.begin(); i != nums.end(); i++) {
    if (*i == val) {
      nums.erase(i);
      i--;
    }
  }

  return nums.size();
}

int main() {
  vector<int> firstInput {3,2,2,3};
  vector<int> secondInput {0,1,2,2,3,0,4,2};

  cout << "Output: " << removeElement(firstInput, 3) << ", nums = ";
  printVector(firstInput);

  cout << "Output: " << removeElement(secondInput, 2) << ", nums = ";
  printVector(secondInput);

  return 0;
}
