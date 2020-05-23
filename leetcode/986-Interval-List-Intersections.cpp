/**
986. Interval List Intersections
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
    The intersection of two closed intervals is a set of real numbers that is either empty, or can be
    represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

// so much more elegant than first sol.. oof
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_size = A.size();
        int B_size = B.size();
        int A_ptr = 0, B_ptr = 0;
        int i = 0;
        vector<vector<int>> res;
        int left = 0, right = 0;
        while (A_ptr < A_size && B_ptr < B_size) {
            left = max(A[A_ptr][0], B[B_ptr][0]);
            right = min(A[A_ptr][1], B[B_ptr][1]);
            // either middle of A and start/end of B or vice versa
            if (left <= right) {
                res.push_back({left, right});
            }
            if (A[A_ptr][1] < B[B_ptr][1]) {
                A_ptr++;
            } else {
                B_ptr++;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_size = A.size();
        int B_size = B.size();
        if (!A_size || !B_size) {
            return vector<vector<int>>();
        }
        int A_max = A[A_size-1][1];
        int B_max = B[B_size-1][1];
        int A_ptr = 0, B_ptr = 0;
        int i = 0;
        vector<vector<int>> res;
        int left, right;
        bool in_interval = false;
        while (i < min(A_max, B_max) && A_ptr < A_size && B_ptr < B_size) {
            if (A[A_ptr][0] > i || B[B_ptr][0] > i) {
                i = max(A[A_ptr][0], B[B_ptr][0]);
                continue;
            }
            if (A[A_ptr][1] < i) {
                A_ptr++;
                continue;
            }
            if (B[B_ptr][1] < i) {
                B_ptr++;
                continue;
            }
            // either middle of A and start/end of B or vice versa
            if (in_interval) {
                if (A[A_ptr][1] == i || B[B_ptr][1] == i) {
                    right = i;
                    res.push_back({left, right});
                    in_interval = false;
                    i = right+1;
                } else {
                    i = min(A[A_ptr][1], B[B_ptr][1]);
                }
            } else {
                left = i;
                in_interval = true;
            }
        }
        
        // close last overlapping interval
        if (in_interval) {
            res.push_back({left, i});
        }
        else { // check for A_ptr[1] == B_ptr[0] or A_ptr[0] == B_ptr[1]
            if (A_max == B_max) {
                if (B[B_size-1][1] == i) { // could do A[A_size-1][1] also
                    res.push_back({i, i});
                }
            } else { // i < A_max || i < B_max
                if (i == B_max) {
                    while (A[A_ptr][1] < i) { // this is ok since A_max > B_max == i
                        A_ptr++;
                    }
                    if (A[A_ptr][0] <= i && A[A_ptr][1] >= i) {
                        res.push_back({i, i});
                    }
                } else if (i == A_max) {
                    while (B[B_ptr][1] < i) { // this is ok since B_max > A_max == i
                        B_ptr++;
                    }
                    if (B[B_ptr][0] <= i && B[B_ptr][1] >= i) {
                        res.push_back({i, i});
                    }
                }
            }
        }
        return res;
    }
};