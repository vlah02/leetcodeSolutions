#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

// Class defining the solution
class Solution {
public:
    // Main function which calculates the maximum sum of a subsequence of nums
    // such that no two numbers in the subsequence are adjacent in the original
    // array by more than k.
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // Get the size of the input vector
        int n = nums.size();

        // Initialize a dynamic programming array to keep track of the maximum sum at each index
        vector<int> dp(n);

        // A double-ended queue (deque) to manage the window of valid elements for the current index
        deque<int> dq;

        // Set an initial value for the max sum as the smallest possible integer
        int maxSum = INT_MIN;

        // Loop through the input vector nums
        for (int i = 0; i < n; ++i) {
            // If the deque is not empty, update the DP value for the current index
            // as the maximum between the current number and the sum of the current number
            // with the maximum sum within the k distance (stored at the front of the deque).
            if (!dq.empty()) {
                dp[i] = max(nums[i], nums[i] + dp[dq.front()]);
            } else {
                dp[i] = nums[i];  // If the deque is empty, simply use the current number
            }

            // Update the maxSum with the maximum sum achieved so far
            maxSum = max(maxSum, dp[i]);

            // Remove the front of the deque if it's out of the current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // If the last element of the deque is less than or equal to the current DP value
            // remove it. This maintains the property that the front of the deque always has
            // the maximum value in the current window.
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            // Only consider adding the current index to the deque if its corresponding DP value is positive
            if (dp[i] > 0) {
                dq.push_back(i);
            }
        }

        // Return the maximum sum achieved
        return maxSum;
    }
};


int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {10, 2, -10, 5, 20};
    int k1 = 2;
    int expected1 = 37;
    assert(solution.constrainedSubsetSum(nums1, k1) == expected1);

    // Test Case 2
    vector<int> nums2 = {-1, -2, -3};
    int k2 = 1;
    int expected2 = -1;
    assert(solution.constrainedSubsetSum(nums2, k2) == expected2);

    // Test Case 3
    vector<int> nums3 = {10, -2, -10, -5, 20};
    int k3 = 2;
    int expected3 = 23;
    assert(solution.constrainedSubsetSum(nums3, k3) == expected3);

    cout << "All test cases passed!" << endl;
    return 0;
}
