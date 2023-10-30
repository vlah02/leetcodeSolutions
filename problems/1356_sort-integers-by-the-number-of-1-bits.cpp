#include <iostream>    // Include for standard input-output stream objects
#include <vector>      // Include for the vector data structure
#include <algorithm>   // Include for the sort algorithm
using namespace std;   // Use the standard namespace to avoid specifying it repeatedly

/**
 * This class provides methods to sort integers based on the number of '1' bits in their binary representation.
 */
class Solution {
public:

    /**
     * Counts the number of '1' bits in the binary representation of a given integer.
     *
     * @param n The integer whose '1' bits are to be counted.
     * @return The count of '1' bits in the binary representation of n.
     */
    int countOnes(int n) {
        int count = 0;  // Initialize the count of '1' bits to 0.

        // While n is not zero, continue to check its bits.
        while(n) {
            count += n & 1;   // If the least significant bit of n is '1', add it to the count.
            n >>= 1;         // Right shift n to check the next bit.
        }

        return count;  // Return the count of '1' bits.
    }

    /**
     * Compares two integers based on the number of '1' bits in their binary representation.
     * If the number of '1' bits is the same, compares the integers themselves.
     *
     * @param a The first integer to compare.
     * @param b The second integer to compare.
     * @return True if a should come before b in the sorted order, false otherwise.
     */
    static bool compareByBits(int a, int b) {
        Solution s;  // Create an instance of the Solution class to access the countOnes method.

        // Get the count of '1' bits for both integers.
        int countA = s.countOnes(a);
        int countB = s.countOnes(b);

        // If both integers have the same number of '1' bits, compare the integers themselves.
        if(countA == countB) {
            return a < b;
        }

        // Otherwise, compare based on the count of '1' bits.
        return countA < countB;
    }

    /**
     * Sorts an array of integers based on the number of '1' bits in their binary representation.
     * If two integers have the same number of '1' bits, they are sorted based on their value.
     *
     * @param arr The array of integers to be sorted.
     * @return The sorted array.
     */
    vector<int> sortByBits(vector<int>& arr) {
        // Use the STL sort function with the custom comparator defined above.
        sort(arr.begin(), arr.end(), compareByBits);

        return arr;  // Return the sorted array.
    }
};

/**
 * Tests the sortByBits function with given input and expected output vectors.
 * Prints the result of the test to the console.
 *
 * @param input The input vector for the test.
 * @param expected The expected output vector for the test.
 */
void test(vector<int>& input, vector<int>& expected) {
    Solution s;  // Create an instance of the Solution class.
    vector<int> result = s.sortByBits(input);  // Get the sorted vector.

    // Check if the result matches the expected output.
    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
        for (int num : result) {
            cout << num << " ";  // Print the incorrect result for debugging.
        }
        cout << endl;
    }
}

/**
 * The main function where the program starts execution.
 */
int main() {
    // Test the sortByBits function with sample inputs and outputs.

    vector<int> input1 = {0,1,2,3,4,5,6,7,8};
    vector<int> expected1 = {0,1,2,4,8,3,5,6,7};
    test(input1, expected1);  // Run the test with the first sample.

    vector<int> input2 = {1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> expected2 = {1,2,4,8,16,32,64,128,256,512,1024};
    test(input2, expected2);  // Run the test with the second sample.

    return 0;  // Indicate that the program executed successfully.
}
