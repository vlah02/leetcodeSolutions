#include <iostream>
#include <cassert>
using namespace std;

// The solution class containing the function to determine if two strings are equal
// after processing backspace ('#') characters.
class Solution {
public:
    // The main function that returns true if both strings are equal after processing backspaces.
    bool backspaceCompare(string s, string t) {
        // Initialize two pointers at the end of the strings.
        int i = s.length() - 1, j = t.length() - 1;

        // Loop until we have processed all characters in both strings.
        while (i >= 0 || j >= 0) {
            // Variables to keep track of the number of backspaces.
            int skipS = 0, skipT = 0;

            // Process the backspaces in string 's'.
            while (i >= 0) {
                // If current character is a backspace, increase the counter and move the pointer.
                if (s[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    // If there's a non-backspace character but we have some backspaces to process, decrement the counter and move the pointer.
                    skipS--, i--;
                } else {
                    // If it's a normal character, break out of the loop.
                    break;
                }
            }

            // Process the backspaces in string 't', similar to above.
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }

            // Compare the current characters of 's' and 't'. If they are not equal, return false.
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // If one of the strings is processed and the other isn't, return false.
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            // Move to the previous character for both strings.
            i--, j--;
        }

        // If all characters have been processed without any mismatches, return true.
        return true;
    }
};

// Test cases to validate the solution.
int main() {
    Solution sol;

    // Test cases with expected results are provided.
    // They check the behavior of the function with different string combinations.

    assert(sol.backspaceCompare("ab#c", "ad#c") == true);  // Both strings become "ac".
    assert(sol.backspaceCompare("ab##", "c#d#") == true);  // Both strings become "".
    assert(sol.backspaceCompare("a#c", "b") == false);     // Strings become "c" and "b" respectively.
    // Additional test cases:
    assert(sol.backspaceCompare("abc", "abcd") == false);  // Strings remain different.
    assert(sol.backspaceCompare("a##c", "#b#c") == true);  // Both strings become "c".
    assert(sol.backspaceCompare("##abc", "abc") == true);  // Both strings become "abc".
    assert(sol.backspaceCompare("", "") == true);          // Both strings are initially empty.
    assert(sol.backspaceCompare("######", "####") == true);// Both strings become empty after processing backspaces.

    // If all assertions pass, we print a success message.
    cout << "All test cases passed!" << endl;
    return 0;
}
