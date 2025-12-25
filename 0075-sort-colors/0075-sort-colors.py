from typing import List, Tuple

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        # Get sorted result using non-mutating quicksort
        sorted_nums = self.quicksort(nums)

        # Copy result back into nums (LeetCode requirement)
        for i in range(len(nums)):
            nums[i] = sorted_nums[i]

    def _partition(self, lst: List[int], pivot: int) -> Tuple[List[int], List[int]]:
        smaller = []
        bigger = []

        for item in lst:
            if item < pivot:
                smaller.append(item)
            else:
                bigger.append(item)

        return smaller, bigger

    def quicksort(self, lst: List[int]) -> List[int]:
        # Base case
        if len(lst) < 2:
            return lst.copy()

        # Choose pivot (last element)
        pivot = lst[-1]

        # Partition excluding pivot
        smaller, bigger = self._partition(lst[:-1], pivot)

        # Recursively sort and combine
        return self.quicksort(smaller) + [pivot] + self.quicksort(bigger)
