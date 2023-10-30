#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to count the number of binary trees that can be formed
    // with the numbers of the array 'arr' as their nodes.
    int numFactoredBinaryTrees(vector<int>& arr) {
        // Modulo constant to prevent integer overflow
        int mod = 1e9 + 7;

        // Sort the array in ascending order.
        sort(arr.begin(), arr.end());

        // A hash table (dp) is initialized to store the number of ways
        // to form binary trees with each number from the 'arr' as root.
        // Initially, each number can form a tree of size 1 (just the root),
        // so they are initialized to 1.
        unordered_map<int, long> dp;
        for(int num : arr) {
            dp[num] = 1;
        }

        // For each number in the sorted 'arr', check all the smaller numbers.
        // If a number is divisible by a smaller number and the result of the division
        // is also present in 'arr', then the number of ways to form trees with the current
        // number as root increases.
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0 && dp.find(arr[i] / arr[j]) != dp.end()) {
                    // Update the number of ways for the current number
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
                    dp[arr[i]] %= mod;
                }
            }
        }

        // Sum all the ways for each number in 'arr' to get the final answer.
        long res = 0;
        for(auto [_, val] : dp) {
            res += val;
            res %= mod;
        }

        return res;
    }
};

// Test function to validate the solution
void test(const vector<int>& input, int expected) {
    Solution solution;
    int result = solution.numFactoredBinaryTrees((vector<int> &) input);
    if (result == expected) {
        cout << "Test passed for input ";
        for (const int& num : input) {
            cout << num << " ";
        }
        cout << ". Output: " << result << "." << endl;
    } else {
        cout << "Test failed for input ";
        for (const int& num : input) {
            cout << num << " ";
        }
        cout << ". Expected: " << expected << ", but got: " << result << "." << endl;
    }
}

int main() {
    // Provided test cases and their expected results
    test({2, 4}, 3);
    test({2, 4, 5, 10}, 7);

    // Additional test cases for further validation
    test({2}, 1);
    test({3, 6, 9}, 4);

    return 0;
}
