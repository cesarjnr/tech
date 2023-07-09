#include <vector>
#include <iostream>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
  int maxConsecutiveOnes = 0;
  int currentCountOfConsecutiveOnes = 0;

  for (auto i = nums.begin(); i != nums.end(); i++) {
    if (*i == 1) {
      currentCountOfConsecutiveOnes++;

      if (currentCountOfConsecutiveOnes > maxConsecutiveOnes) {
        maxConsecutiveOnes = currentCountOfConsecutiveOnes;
      }
    } else {
      currentCountOfConsecutiveOnes = 0;
    }
  }

  return maxConsecutiveOnes;
}

int main() {
  vector<int> firstInput {1,1,0,1,1,1};
  vector<int> secondInput {1,0,1,1,0,1};

  cout << "Output: " << findMaxConsecutiveOnes(firstInput) << "\n";
  cout << "Output: " << findMaxConsecutiveOnes(secondInput) << "\n";

  return 0;
}
