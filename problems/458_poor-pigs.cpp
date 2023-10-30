#include <iostream>
#include <cmath>      // Include for mathematical operations, particularly power function
using namespace std;

/**
 * This class provides a solution to determine the minimum number of pigs required
 * to figure out which bucket contains poison within a given time frame.
 */
class Solution {
public:
    /**
     * Determines the minimum number of pigs required to figure out which bucket contains poison.
     *
     * @param buckets The total number of buckets.
     * @param minutesToDie The time it takes for a pig to die after drinking from a poisonous bucket.
     * @param minutesToTest The total time we have to determine which bucket contains the poison.
     * @return The minimum number of pigs required.
     */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // The number of states or sessions a pig can be tested in (including the pig staying alive).
        int states = (minutesToTest / minutesToDie) + 1;

        int pigs = 0;  // Initialize the number of pigs needed to 0.

        // Each pig can be used to represent a state by observing when it dies.
        // We need to find the number of pigs required such that the number of states raised to the power of pigs
        // is greater than or equal to the number of buckets.
        while (pow(states, pigs) < buckets) {
            pigs++;
        }

        return pigs;  // Return the number of pigs required.
    }
};

// Testing framework:

/**
 * Test the solution with given parameters and expected output.
 *
 * @param buckets The total number of buckets for this test.
 * @param minutesToDie The time it takes for a pig to die in this test.
 * @param minutesToTest The total time we have for this test.
 * @param expected The expected number of pigs required for this test.
 */
void test(int buckets, int minutesToDie, int minutesToTest, int expected) {
    Solution s;
    int result = s.poorPigs(buckets, minutesToDie, minutesToTest);

    // Print the result of the test case.
    if (result == expected) {
        cout << "Test for buckets = " << buckets << ", minutesToDie = " << minutesToDie << ", minutesToTest = " << minutesToTest << " passed!" << endl;
    } else {
        cout << "Test for buckets = " << buckets << ", minutesToDie = " << minutesToDie << ", minutesToTest = " << minutesToTest << " failed! Expected " << expected << " but got " << result << "." << endl;
    }
}

int main() {
    // Sample test cases:
    test(4, 15, 15, 2);
    test(4, 15, 30, 2);

    return 0;  // Indicate that the program executed successfully.
}
