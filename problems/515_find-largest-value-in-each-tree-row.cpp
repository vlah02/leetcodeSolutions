#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;                // Value of the node
    TreeNode *left;         // Pointer to left child node
    TreeNode *right;        // Pointer to right child node
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor taking value as argument
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Constructor taking value and child nodes
};

// Utility function to build a tree from a vector using BFS
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == INT_MIN) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};  // If root is null, return an empty vector

        vector<int> result;    // Vector to store the result - largest values at each tree level
        list<TreeNode*> lst;   // Using list as a double-ended queue to perform BFS on the tree
        lst.push_back(root);   // Start BFS from root
        lst.push_back(NULL);   // A marker to indicate the end of a level in BFS

        int maxVal = INT_MIN;  // Initialize max value for each level

        // BFS traversal
        while (!lst.empty()) {
            TreeNode* node = lst.front(); lst.pop_front();  // Get the front node

            // If we hit the marker (end of current level)
            if (node == NULL) {
                result.push_back(maxVal);  // Save the largest value of current level to result
                if (!lst.empty()) lst.push_back(NULL);  // If there are more nodes to process, add a new level marker
                maxVal = INT_MIN;  // Reset max value for next level
            } else {
                maxVal = max(maxVal, node->val);  // Update max value using current node's value
                // If left or right child exists, add them to the queue for BFS
                if (node->left) lst.push_back(node->left);
                if (node->right) lst.push_back(node->right);
            }
        }

        return result;  // Return the list of largest values from each level
    }
};

// Test function
void test(const vector<int>& nodes) {
    TreeNode* root = buildTree(nodes);
    Solution solution;
    vector<int> result = solution.largestValues(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to execute tests
int main() {
    test({1, 3, 2, 5, 3, INT_MIN, 9});  // Expected: 1 3 9
    test({1, 2, 3});                   // Expected: 1 3
    return 0;
}