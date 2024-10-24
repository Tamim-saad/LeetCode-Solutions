// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Handle edge case where input is empty or has only one interval
        if (intervals.size() <= 1) {
            return 0;
        }

        // Sort intervals by their end time (and if end times are equal, by start time)
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];  // Sort by end time in ascending order
             });

        // 't' keeps track of the end time of the last valid interval
        int t = intervals[0][1];  // Initialize 't' to the end time of the first interval
        int count = 1;            // Count the first interval as valid (non-overlapping)

        // Traverse the sorted intervals starting from the second one
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval starts after or at the end of the last valid one
            if (intervals[i][0] >= t) {
                count++;              // Count this interval as non-overlapping
                t = intervals[i][1];  // Update 't' to the end time of the current interval
            }
        }

        // The number of intervals to remove is the total number of intervals minus the valid ones
        return intervals.size() - count;
    }
};
