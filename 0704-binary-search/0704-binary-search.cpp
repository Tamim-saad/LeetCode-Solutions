class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Step 1: Set the starting and ending indices
        int low = 0;                  // first index
        int high = nums.size() - 1;   // last index

        // Step 2: Continue searching while the range is valid
        while (low <= high) {

            // Step 3: Find the middle index
            int mid = ( low + high ) / 2;

            // Step 4: If middle element is the target, return index
            if (nums[mid] == target) {
                return mid;
            }

            // Step 5: If target is bigger, search right half
            else if (nums[mid] < target) {
                low = mid + 1;
            }

            // Step 6: If target is smaller, search left half
            else {
                high = mid - 1;
            }
        }

        // Step 7: Target not found
        return -1;
    }
};
