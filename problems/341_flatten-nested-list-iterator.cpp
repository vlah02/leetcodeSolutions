#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

// Assuming a NestedInteger class is provided, which has the following methods:
// bool isInteger() const;
// int getInteger() const;
// const vector<NestedInteger> &getList() const;

// For the sake of the example, I'll provide a simple mock of the NestedInteger class.
class NestedInteger {
private:
    bool isInt;
    int value;
    vector<NestedInteger> list;

public:
    NestedInteger(int val) : isInt(true), value(val) {}
    NestedInteger(const vector<NestedInteger>& lst) : isInt(false), list(lst) {}

    bool isInteger() const { return isInt; }
    int getInteger() const { return value; }
    const vector<NestedInteger> &getList() const { return list; }
};

/**
 * The NestedIterator class is designed to flatten a nested list of integers.
 * Each element in the list is either an integer or another list.
 * The primary goal of this iterator is to return each integer in the nested list one by one in a sequential manner.
 */
class NestedIterator {
private:
    // Using a stack to keep track of the elements yet to be traversed.
    stack<NestedInteger> nodes;

public:
    /**
     * Constructor: Initializes the iterator with the provided nested list.
     * It pushes elements of the nested list onto the stack in reverse order
     * to facilitate LIFO (Last In, First Out) access, which is characteristic of a stack.
     *
     * @param nestedList: A reference to the list of NestedInteger.
     */
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--) {
            nodes.push(nestedList[i]);
        }
    }

    /**
     * next() method: Returns the next integer in the nested list.
     *
     * @return: The next integer.
     */
    int next() {
        // Getting the integer on top of the stack, and then popping it.
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }

    /**
     * hasNext() method: Checks if there are more integers left in the nested list.
     *
     * @return: true if there are more integers, false otherwise.
     */
    bool hasNext() {
        // Loop through the elements in the stack until we find an integer or the stack becomes empty.
        while (!nodes.empty()) {
            if (nodes.top().isInteger()) {
                return true;
            }

            // If the top element is a list, pop it off the stack,
            // and push its contents onto the stack in reverse order.
            vector<NestedInteger> topList = nodes.top().getList();
            nodes.pop();
            for (int i = topList.size() - 1; i >= 0; i--) {
                nodes.push(topList[i]);
            }
        }
        return false;
    }
};


int main() {
    // Test case 1
    {
        vector<NestedInteger> nestedList = {NestedInteger({1, 1}), NestedInteger(2), NestedInteger({1, 1})};
        NestedIterator ni(nestedList);
        vector<int> output;
        while(ni.hasNext()) {
            output.push_back(ni.next());
        }
        assert(output == vector<int>({1, 1, 2, 1, 1}));
    }

    // Test case 2
    {
        vector<NestedInteger> nestedList = {NestedInteger(1), NestedInteger({4, NestedInteger({6})})};
        NestedIterator ni(nestedList);
        vector<int> output;
        while(ni.hasNext()) {
            output.push_back(ni.next());
        }
        assert(output == vector<int>({1, 4, 6}));
    }

    cout << "All test cases passed!" << endl;
    return 0;
}
