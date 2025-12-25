from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.merge_sort(0, len(nums) - 1, nums)
        return nums

    def merge_sort(self, l: int, h: int, arr: List[int]) -> None:
        # Base case: single element
        if l >= h:
            return

        mid = (l + h) // 2

        # Divide into two parts
        self.merge_sort(l, mid, arr)
        self.merge_sort(mid + 1, h, arr)

        # Merge step (same logic as your C++ code)
        i = l
        j = mid + 1
        temp = []

        while i <= mid and j <= h:
            if arr[i] < arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                j += 1

        # Remaining elements
        while i <= mid:
            temp.append(arr[i])
            i += 1

        while j <= h:
            temp.append(arr[j])
            j += 1

        # Copy back to original array
        for idx in range(len(temp)):
            arr[l + idx] = temp[idx]
