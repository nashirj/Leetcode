'''
239. Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7 

Constraints:
    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length
'''

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        '''
        keep track of increasing indices of decreasing values
        leftmost value of queue should be index of largest element in current window
        '''
        res = []
        dq = collections.deque()
        n = len(nums)
        
        for i in range(n): # O(n)
            # want a decreasing monotonic queue, if nums[i] is gte any elems on right, pop those elems
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop() # this line happens at most n times
            
            dq.append(i)

            if i - dq[0] >= k: # if index at dq[0] is out of range, pop it
                dq.popleft()
            
            if i >= k-1:
                res.append(nums[dq[0]])
        
        return res

    def BRUTEFORCE_maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        '''
        brute force: n * k time
        '''
        n = len(nums)
        res = []
        for i in range(n-k+1):
            res.append(max(nums[i:i+k]))
        return res
        
    