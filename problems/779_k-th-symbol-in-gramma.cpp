#include <iostream>
using namespace std;

class Solution {
public:
    // This function returns the kth grammar symbol in the nth row of a grammar sequence.
    int kthGrammar(int n, int k) {
        // Base case: If the row is the first row, the only symbol is 0.
        if (n == 1) {
            return 0;
        }

        // If k is in the first half of the nth row,
        // the kth symbol in the nth row is the same as the kth symbol in the (n-1)th row.
        if (k <= (1 << (n - 2))) { // 1 << (n-2) calculates 2^(n-2) which gives the length of half the row.
            return kthGrammar(n - 1, k);
        }
            // If k is in the second half of the nth row,
            // the kth symbol in the nth row is the opposite of the (k - 2^(n-2))th symbol in the (n-1)th row.
        else {
            return 1 - kthGrammar(n - 1, k - (1 << (n - 2)));
        }
    }
};

// This function tests the kthGrammar function with given input and expected output.
void test(int n, int k, int expected) {
    Solution solution;
    int result = solution.kthGrammar(n, k);
    // Checks if the result matches the expected output.
    if (result == expected) {
        cout << "Test passed for input n = " << n << " and k = " << k << ". Output: " << result << "." << endl;
    } else {
        cout << "Test failed for input n = " << n << " and k = " << k << ". Expected: " << expected << ", but got: " << result << "." << endl;
    }
}

int main() {
    // Provided test cases and their expected results.
    test(1, 1, 0);
    test(2, 1, 0);
    test(2, 2, 1);

    // Additional test cases for further validation.
    test(3, 1, 0);
    test(3, 2, 1);
    test(3, 3, 1);
    test(3, 4, 0);
    test(4, 5, 1);
    test(4, 6, 0);
    test(4, 7, 0);
    test(4, 8, 1);

    return 0;
}
