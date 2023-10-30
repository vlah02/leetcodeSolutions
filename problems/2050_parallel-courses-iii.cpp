#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    /**
     * Determines the minimum time required to complete all courses given certain prerequisites.
     *
     * @param n An integer, the total number of courses.
     * @param relations A 2D vector specifying course prerequisites. If relations[i] = {x, y},
     *                  it means course x should be taken before course y.
     * @param time A vector where time[i] denotes the time required to complete (i+1)th course.
     * @return The minimum time required to complete all courses.
     */
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        // Represents adjacency list of the graph. Each course can have multiple subsequent courses.
        vector<vector<int>> graph(n);

        // Tracks in-degrees (number of prerequisites) for each course.
        vector<int> inDegree(n, 0);

        // Construct the graph and populate in-degrees based on given relations.
        for(auto &relation: relations) {
            graph[relation[0] - 1].push_back(relation[1] - 1);
            inDegree[relation[1] - 1]++;
        }

        // Queue to process courses that have all their prerequisites met.
        queue<int> q;

        // Represents the starting time for each course.
        vector<int> startTimes(n, 0);

        // Enqueue courses that have no prerequisites (in-degree is 0).
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the courses.
        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            // For each subsequent course of the current course:
            for(int neighbor: graph[curr]) {
                // Update the start time for the subsequent course based on the time taken by the current course.
                startTimes[neighbor] = max(startTimes[neighbor], startTimes[curr] + time[curr]);

                // Reduce in-degree for the subsequent course (marking the current course as "done").
                if(--inDegree[neighbor] == 0) {
                    // If all prerequisites are met for the subsequent course, add it to the queue.
                    q.push(neighbor);
                }
            }
        }

        // Calculate the minimum time required to complete all courses.
        int result = 0;
        for(int i = 0; i < n; i++) {
            result = max(result, startTimes[i] + time[i]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test cases to validate the solution.

    // Test case 1: Courses with a common prerequisite.
    vector<vector<int>> relations1 = {{1,3},{2,3}};
    vector<int> time1 = {3,2,5};
    assert(sol.minimumTime(3, relations1, time1) == 8);  // Expected output: 8

    // Test case 2: Courses with multiple prerequisites.
    vector<vector<int>> relations2 = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time2 = {1,2,3,4,5};
    assert(sol.minimumTime(5, relations2, time2) == 12);  // Expected output: 12

    // Test case 3: Courses with no prerequisites.
    vector<vector<int>> relations3 = {};
    vector<int> time3 = {1,2,3};
    assert(sol.minimumTime(3, relations3, time3) == 3);  // Expected output: 3 (The longest course takes 3 months.)

    // Test case 4: Single course.
    vector<vector<int>> relations4 = {};
    vector<int> time4 = {5};
    assert(sol.minimumTime(1, relations4, time4) == 5);  // Expected output: 5

    // Test case 5: Complex relationships.
    vector<vector<int>> relations5 = {{1,2},{1,3},{2,4},{2,5},{3,6},{3,7}};
    vector<int> time5 = {1,2,2,3,3,2,1};
    assert(sol.minimumTime(7, relations5, time5) == 6);  // Expected output: 6

    // Success message if all assertions pass.
    cout << "All test cases passed!" << endl;

    return 0;
}
