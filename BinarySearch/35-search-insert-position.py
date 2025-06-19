def searchInsert(nums: list[int], target: int) -> int:
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

    if target < nums[low]:
        if low == 0:
            return 0
        return low-1
    else:
        return low+1

a = searchInsert([1,3,5,6], 7)
print(a)