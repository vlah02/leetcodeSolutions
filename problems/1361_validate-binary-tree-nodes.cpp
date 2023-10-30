#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // This vector keeps track of how many times a node is referred as a child (either left or right)
        vector<int> parentCounts(n, 0);

        // Loop through all the nodes
        for (int i = 0; i < n; i++) {
            // If node i has a left child, increment the left child's parent count
            if (leftChild[i] != -1) {
                parentCounts[leftChild[i]]++;
            }

            // If node i has a right child, increment the right child's parent count
            if (rightChild[i] != -1) {
                parentCounts[rightChild[i]]++;
            }
        }

        // This variable will keep count of nodes that have no parents.
        // For a valid binary tree, this should be exactly 1 (the root node)
        int rootCount = 0;

        // This variable will keep the identified root of the tree
        int root = -1;

        // Loop through all the nodes again to identify potential roots or nodes with more than one parent
        for (int i = 0; i < n; i++) {
            // If a node is not a child to any other node, it's a potential root
            if (parentCounts[i] == 0) {
                rootCount++;
                root = i;
            }
                // If a node is referred as a child more than once, it's not a valid tree
            else if (parentCounts[i] > 1) {
                return false;
            }
        }

        // If there is not exactly one root node, it's not a valid binary tree
        if (rootCount != 1) {
            return false;
        }

        // BFS to verify if all nodes are connected. This makes sure that all nodes are part of the tree rooted at 'root'
        queue<int> q;
        vector<int> visited(n, 0);  // Keeps track of nodes that are visited in BFS traversal
        q.push(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Mark the current node as visited
            visited[node] = 1;

            // If the current node has a left child and that child is not visited, push it to the queue
            if (leftChild[node] != -1 && !visited[leftChild[node]]) {
                q.push(leftChild[node]);
            }
            // Similarly, push the right child to the queue if it's not visited
            if (rightChild[node] != -1 && !visited[rightChild[node]]) {
                q.push(rightChild[node]);
            }
        }

        // After BFS traversal, if there's any node that hasn't been visited, it means the tree is not connected
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        // If all checks passed, it's a valid binary tree
        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 4;
    vector<int> leftChild1 = {1,-1,3,-1};
    vector<int> rightChild1 = {2,-1,-1,-1};
    assert(solution.validateBinaryTreeNodes(n1, leftChild1, rightChild1) == true);

    // Test case 2
    int n2 = 4;
    vector<int> leftChild2 = {1,-1,3,-1};
    vector<int> rightChild2 = {2,3,-1,-1};
    assert(solution.validateBinaryTreeNodes(n2, leftChild2, rightChild2) == false);

    // Test case 3
    int n3 = 2;
    vector<int> leftChild3 = {1,0};
    vector<int> rightChild3 = {-1,-1};
    assert(solution.validateBinaryTreeNodes(n3, leftChild3, rightChild3) == false);

    cout << "All test cases passed!" << endl;
    return 0;
}
