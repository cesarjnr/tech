#include <vector>
#include <iostream>

using namespace std;

int dominantIndex(vector<int>& nums) {
  int largestElement = 0;
  int largestElementIndex = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > largestElement) {
      largestElement = nums[i];
      largestElementIndex = i;
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    if (i != largestElementIndex && nums[i] > (largestElement / 2)) {
      return -1;
    }
  }

  return largestElementIndex;
}

int main() {
  vector<int> firstInput {3,6,1,0};
  vector<int> secondInput {1,2,3,4};
  vector<int> thirdInput {1};

  cout << "Output: " << dominantIndex(firstInput) << "\n";
  cout << "Output: " << dominantIndex(secondInput) << "\n";
  cout << "Output: " << dominantIndex(thirdInput) << "\n";

  return 0;
}
