#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // This function aims to get the rowIndex-th row (0-based) from Pascal's triangle.
    vector<int> getRow(int rowIndex) {

        // Initialize a row of length 'rowIndex + 1' with all zeros.
        // This will eventually store the values of the desired row from Pascal's triangle.
        vector<int> row(rowIndex + 1, 0);

        // The first element of any row in Pascal's triangle is always 1.
        row[0] = 1;

        // Loop from 1 through rowIndex to fill in the values for the desired row.
        for (int i = 1; i <= rowIndex; ++i) {

            // Start from the current index and work backwards.
            // The reason we go backwards is to use previously computed values without overwriting them.
            for (int j = i; j >= 1; --j) {

                // Each element in Pascal's triangle is the sum of the element above and the element to the top-left.
                // This line updates the current element with the value of its left neighbor from the previous row.
                row[j] += row[j - 1];
            }
        }

        // Return the completed row from Pascal's triangle.
        return row;
    }
};

int main() {
    Solution solution;

    // Test the function with various rowIndex values to ensure correctness.

    // For rowIndex = 3, Pascal's triangle looks like:
    //     1
    //    1 1
    //   1 2 1
    //  1 3 3 1
    // The 4th row (0-based index) is [1, 3, 3, 1]
    assert(solution.getRow(3) == vector<int>({1, 3, 3, 1}));

    // For rowIndex = 0, Pascal's triangle has just one row: [1]
    assert(solution.getRow(0) == vector<int>({1}));

    // For rowIndex = 1, Pascal's triangle looks like:
    //   1
    //  1 1
    // The 2nd row (0-based index) is [1, 1]
    assert(solution.getRow(1) == vector<int>({1, 1}));

    cout << "All test cases passed!" << endl;
    return 0;
}
