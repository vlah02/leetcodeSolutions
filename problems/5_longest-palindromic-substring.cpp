#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the longest palindromic substring in a string `s`
    string longestPalindrome(string s) {
        // If the string has less than 2 characters, the whole string is the longest palindrome
        if (s.size() < 2) return s;

        int start = 0;  // Starting index of the longest palindromic substring
        int max_len = 1;  // Maximum length of palindrome found so far

        // Loop over each character of the string
        for (int i = 0; i < s.size(); ++i) {
            // Check for longest palindrome with `i` as the middle element
            checkPalindrome(s, i, i, start, max_len);

            // Check for longest palindrome with `i` and `i+1` as the middle elements
            checkPalindrome(s, i, i + 1, start, max_len);
        }

        // Return the longest palindromic substring found
        return s.substr(start, max_len);
    }

private:
    // Helper function to check and update the longest palindrome
    void checkPalindrome(const string &s, int left, int right, int &start, int &max_len) {
        // Expand outwards while the characters match and we are within the bounds of the string
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        int len = right - left - 1;  // Calculate the palindrome's length

        // Update longest palindrome details if this palindrome is longer than the previously found one
        if (len > max_len) {
            max_len = len;
            start = left + 1;
        }
    }
};

// Test function to validate the solution with sample test cases
void test(const string& input, const string& expected) {
    Solution solution;
    string result = solution.longestPalindrome(input);
    if (result == expected) {
        cout << "Test passed for input \"" << input << "\". Output: \"" << result << "\"." << endl;
    } else {
        cout << "Test failed for input \"" << input << "\". Expected: \"" << expected << "\", but got: \"" << result << "\"." << endl;
    }
}

int main() {
    // Provided test cases
    test("babad", "bab");  // "aba" is also a valid answer
    test("cbbd", "bb");

    // Additional test cases for further validation
    test("a", "a");
    test("ac", "a");
    test("aa", "aa");
    test("racecar", "racecar");
    test("forgeeksskeegfor", "geeksskeeg");

    return 0;
}
