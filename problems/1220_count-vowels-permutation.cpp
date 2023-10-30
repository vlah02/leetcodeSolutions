#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        // This constant is set for modular arithmetic to prevent overflow.
        const int MOD = 1e9 + 7;

        // Initializing the number of permutations for each vowel
        // for string length 1 (base case)
        long prev[5] = {1, 1, 1, 1, 1}; // Represents 'a', 'e', 'i', 'o', 'u'
        long cur[5] = {0}; // Current state permutations count.

        // Looping through string length from 2 to n
        for (int i = 2; i <= n; i++) {
            // These conditions define which vowels can follow the current vowel.
            // For example, after 'a' only 'e' can come, hence cur[0] = prev[1]
            cur[0] = prev[1];
            cur[1] = (prev[0] + prev[2]) % MOD; // 'e' can be followed by 'a' or 'i'
            cur[2] = (prev[0] + prev[1] + prev[3] + prev[4]) % MOD; // 'i' can be followed by 'a', 'e', 'o', or 'u'
            cur[3] = (prev[2] + prev[4]) % MOD; // 'o' can be followed by 'i' or 'u'
            cur[4] = prev[0]; // 'u' can be followed by 'a'

            // After calculating the permutations for current length, set previous state to current
            for(int j = 0; j < 5; j++) {
                prev[j] = cur[j];
                cur[j] = 0;
            }
        }

        long result = 0;
        // Summing up all permutations for the vowels for string length 'n'
        for (int j = 0; j < 5; j++) {
            result = (result + prev[j]) % MOD;
        }
        return result;
    }
};

// Testing framework:
void test(int n, int expected) {
    Solution s;
    int result = s.countVowelPermutation(n);

    if (result == expected) {
        cout << "Test for n = " << n << " passed!" << endl;
    } else {
        cout << "Test for n = " << n << " failed! Expected " << expected << " but got " << result << "." << endl;
    }
}

int main() {
    test(1, 5);  // All possible strings are: "a", "e", "i" , "o" and "u".
    test(2, 10); // All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
    test(5, 68); //

    return 0;
}
