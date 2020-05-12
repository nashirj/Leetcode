'''
540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element
    appears exactly twice, except for one element which appears exactly once.
    Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10 

Note: Your solution should run in O(log n) time and O(1) space.
'''

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums)-1
        while True:
            mid = lo + (hi-lo)//2
            # only check even indices
            if mid % 2 == 1:
                mid -= 1
            # if nums[mid] == nums[mid+1], single is to the right
            if mid < hi and nums[mid] == nums[mid+1]:
                lo = mid+2
            # if nums[mid] == nums[mid-1], single is to the left
            elif mid > lo and nums[mid] == nums[mid-1]:
                hi = mid-2
            # else, nums[mid] is single
            else:
                return nums[mid]

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums)-1
        mid = lo + (hi-lo)//2
        while lo+1 < hi: # we compare left and right, so if lo == 0 don't want to loop
            mid = lo + (hi-lo)//2
            if mid % 2 == 0:
                # single number hasn't happened yet, is to right
                if nums[mid] == nums[mid+1]:
                    lo = mid
                else: # single number is to left, or is at mid
                    # single is always at an even index
                    if nums[mid] != nums[mid-1]:
                        return nums[mid]
                    hi = mid
            else:
                # single number hasn't happened yet, is to right
                if nums[mid] != nums[mid+1]:
                    lo = mid
                # single number is to left
                else:
                    hi = mid
        
        if lo == hi: # lo is even
            # single is at far left or far right, as is lo
            return nums[lo]
        elif lo+1 == hi: # lo is odd
            # single is at far left, hi is 2nd elem
            if hi == 1:
                return nums[0]
            # single is at far right, hi is 2nd to last elem
            else:
                return nums[-1]
        return nums[mid]