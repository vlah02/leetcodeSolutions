#include <iostream>
#include <cmath>
#include <cassert>

class Solution {
public:
    // Function to check whether the given number 'n' is a power of four.
    bool isPowerOfFour(int n) {
        // If the number is less than or equal to 0, it can't be a power of four.
        if (n <= 0)
            return false;

        // Compute the square root of the number.
        // For a number to be a power of four, it should be a perfect square
        // and the square root should be a power of two.
        int root = sqrt(n);

        // The first condition (root * root == n) checks whether 'n' is a perfect square.
        // The second condition (root & (root - 1)) == 0 checks whether the square root is a power of two.
        // This is based on the property that only powers of two have a single '1' bit in their binary representation.
        // Subtracting 1 flips the rightmost '1' bit and all the bits to its right.
        // A bitwise AND between the number and its decreased version will be zero if the number is a power of two.
        return root * root == n && (root & (root - 1)) == 0;
    }
};


int main() {
    Solution s;

    // Test case 1:
    int input1 = 16;
    bool expected1 = true;
    assert(s.isPowerOfFour(input1) == expected1);
    std::cout << "Test case 1 passed!" << std::endl;

    // Test case 2:
    int input2 = 5;
    bool expected2 = false;
    assert(s.isPowerOfFour(input2) == expected2);
    std::cout << "Test case 2 passed!" << std::endl;

    // Test case 3:
    int input3 = 1;
    bool expected3 = true;
    assert(s.isPowerOfFour(input3) == expected3);
    std::cout << "Test case 3 passed!" << std::endl;


    return 0;
}
