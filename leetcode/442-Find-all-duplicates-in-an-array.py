'''
442. Find All Duplicates in an Array
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
'''

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # brute force: n^2 check each elem and append only if there is only occurence of it in array
        # better: nlogn sort, append only if there are not two adjacent elements
        # better: O(n) space, use hashmap, if val already in map, remove. add all vals that are not in map
        # better: O(n), create array of size n initialized with false, toggle for each element in array. if true, add val to res
        # best: no extra space, O(n) time, for each num in nums, flip sign of nums[num-1]. if nums[num-1] < 0, then num-1 occured twice. append num. reset arr before returning
        
        res = []
        if not nums: return res
        for num in nums:
            index = abs(num)-1
            if nums[index] < 0:
                res.append(index+1)
            nums[index] = -nums[index]
        for i in range(len(nums)):
            nums[i] = abs(nums[i])
            
        return res
