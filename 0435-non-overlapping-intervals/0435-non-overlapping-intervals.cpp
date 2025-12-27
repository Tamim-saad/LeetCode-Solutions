class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Edge case: no intervals means nothing to remove
        if (intervals.empty()) return 0;

        // --------------------------------------------------
        // STEP 1: Sort intervals by END time
        // --------------------------------------------------
        // Why?
        // Choosing the interval that ends earliest leaves
        // the most room for future intervals.
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // --------------------------------------------------
        // STEP 2: Greedily select non-overlapping intervals
        // --------------------------------------------------

        int count = 1;  
        // We always select the first interval after sorting
        // because it has the earliest end time

        int latest_end = intervals[0][1];
        // latest_end keeps track of when the room becomes free again

        // --------------------------------------------------
        // STEP 3: Iterate through remaining intervals
        // --------------------------------------------------
        for (int i = 1; i < intervals.size(); i++) {

            // If current interval starts AFTER or AT the last end time,
            // then it does NOT overlap
            if (intervals[i][0] >= latest_end) {

                // We can safely take this interval
                count++;

                // Update the end time
                latest_end = intervals[i][1];
            }
            // Else:
            // This interval overlaps, so we SKIP it (i.e., remove it)
        }

        // --------------------------------------------------
        // STEP 4: Compute minimum removals
        // --------------------------------------------------
        // Total intervals - maximum non-overlapping intervals
        return intervals.size() - count;
    }
};
