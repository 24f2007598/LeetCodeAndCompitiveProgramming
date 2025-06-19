#0ms, Beats 100%
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            if target < nums[mid]:
                high = mid - 1
            elif target > nums[mid]:
                low = mid + 1

        if low > high:
            return low
        else:
            if high < 0:
                return 0
            else:
                return high