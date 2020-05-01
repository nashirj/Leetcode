/*
278. First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, mid = 1;
        while (lo < n) {
            mid = lo + (n-lo)/2;
            if (isBadVersion(mid)) {
                n = mid;
            } else {
                lo = mid+1;
            }
        }
        // lo == n, so we have honed in on first bad
        return lo;
    }
};

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1))
            return 1;
        int low = 1, high = n, middle;
        while(low <= high){
            //middle = (high + low)/2;] can overflow
            //low/2 + high/2 != (high + low)/2, e.g. low = 3, high = 5, so instead use:
            middle = low + (high - low)/2;
            
            if (isBadVersion(middle))
                high = middle - 1;
            else{
                if (isBadVersion(middle+1))
                    break;
                else
                    low = middle + 1;
            }
        }
        return middle+1;
    }
};