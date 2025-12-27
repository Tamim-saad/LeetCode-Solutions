from typing import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        # --------------------------------------------------
        # Edge case: no intervals means nothing to remove
        # --------------------------------------------------
        if not intervals:
            return 0

        # --------------------------------------------------
        # STEP 1: Sort intervals by END time
        # --------------------------------------------------
        # Why?
        # Choosing the interval that ends earliest leaves
        # the most room for future intervals.
        intervals.sort(key=lambda x: x[1])

        # --------------------------------------------------
        # STEP 2: Greedily select non-overlapping intervals
        # --------------------------------------------------

        count = 1
        # We always select the first interval after sorting
        # because it has the earliest end time

        latest_end = intervals[0][1]
        # latest_end keeps track of when the room becomes free again

        # --------------------------------------------------
        # STEP 3: Iterate through remaining intervals
        # --------------------------------------------------
        for i in range(1, len(intervals)):

            # If the current interval starts AFTER or AT
            # the end of the last selected interval,
            # then it does NOT overlap
            if intervals[i][0] >= latest_end:

                # We can safely take this interval
                count += 1

                # Update the end time
                latest_end = intervals[i][1]

            # Else:
            # This interval overlaps, so we SKIP it (i.e., remove it)

        # --------------------------------------------------
        # STEP 4: Compute minimum removals
        # --------------------------------------------------
        # Total intervals - maximum non-overlapping intervals
        return len(intervals) - count
