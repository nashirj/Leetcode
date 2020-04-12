/*
1046. Last Stone Weight
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.
Suppose the stones have weights x and y with x <= y.
The result of this smash is:
    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left. Return the weight of this stone (or 0 if there are no stones left.)

Example 1:
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
**/

// funnily enough, this solution is slower, but I imagine it scales better since it is O(nlogn)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stone_heap(stones.begin(), stones.end());
        while (stone_heap.size() > 1) {
            int y = stone_heap.top();
            stone_heap.pop();
            int x = stone_heap.top();
            stone_heap.pop();
            if (x < y) {
                stone_heap.push(y-x);
            }
        }
        return (stone_heap.size() == 1) ? stone_heap.top() : 0;
    }
};

// O(n^2logn) lol so bad
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int num_stones = stones.size();
        while (num_stones > 1) {
            sort(stones.begin(), stones.end());
            if (stones[num_stones-1] > stones[num_stones-2]) {
                stones[num_stones-2] = stones[num_stones-1] - stones[num_stones-2];
                stones.pop_back();
            } else {
                stones.pop_back();
                stones.pop_back();
            }
            num_stones = stones.size();
        }
        return (stones.size() == 1) ? stones[0] : 0;
    }
};