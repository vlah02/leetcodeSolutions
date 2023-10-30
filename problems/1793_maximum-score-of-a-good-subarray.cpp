#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    // This function calculates the maximum score for a subarray of the given 'nums' array.
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();   // Store the size of the array.

        // Initialize two pointers, 'left' and 'right', to the index 'k'.
        int left = k, right = k;

        // The minimum value within the subarray is initialized to the value at index 'k'.
        int minValue = nums[k];

        // Initialize the maximum score to the value of 'minValue' (a subarray of size 1 at index 'k').
        int maxScore = minValue;

        // While the 'left' pointer has not reached the beginning or the 'right' pointer has not reached the end:
        while (left > 0 || right < n - 1) {
            // If the 'left' pointer is at the beginning, move the 'right' pointer to the right.
            if (left == 0) {
                right++;
            }
                // If the 'right' pointer is at the end, move the 'left' pointer to the left.
            else if (right == n - 1) {
                left--;
            }
                // If the value to the left of 'left' is less than the value to the right of 'right', move the 'right' pointer.
            else if (nums[left - 1] < nums[right + 1]) {
                right++;
            }
                // Otherwise, move the 'left' pointer.
            else {
                left--;
            }

            // Update the 'minValue' to be the minimum value within the new subarray.
            minValue = min(minValue, min(nums[left], nums[right]));

            // Update the maximum score based on the new 'minValue' and the size of the new subarray.
            maxScore = max(maxScore, minValue * (right - left + 1));
        }

        // Return the computed maximum score.
        return maxScore;
    }
};

int main() {
    Solution sol;

    // Test case 1
    {
        std::vector<int> nums = {1,4,3,7,4,5};
        int k = 3;
        int result = sol.maximumScore(nums, k);
        assert(result == 15);
        std::cout << "Test case 1 passed!" << std::endl;
    }

    // Test case 2
    {
        std::vector<int> nums = {5, 5, 4, 5, 4, 1, 1, 1};
        int k = 0;
        int result = sol.maximumScore(nums, k);
        assert(result == 20);
        std::cout << "Test case 2 passed!" << std::endl;
    }

    return 0;
}
