/*
204. Count Primes

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/


class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = isPrime[1] = false;
        
        int numPrimes = 0;
        
        long long p = 2;
        while(p * p < n){
            if (isPrime[p]){
                for (long long i = p * p; (i < n) && (i >= 0); i += p){
                    if (i < 0) break;
                    isPrime[i] = false;
                }
                numPrimes++;
            }
            p++;
        }
        
        while (p < n){
            if (isPrime[p])
                numPrimes++;
            p++;
        }
            
        
        return numPrimes;
        
    }
};



class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = isPrime[1] = false;
        
        int numPrimes = 0;
        
        for (long long p = 2; p < n; p++){
            if (isPrime[p]){
                for (long long i = p * p; (i < n) && (i >= 0); i += p){
                    if (i < 0) break;
                    isPrime[i] = false;
                }
                
                numPrimes++;
            }
        }
        
        return numPrimes;
        
    }
};


class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        int numPrimes = 0;
        
        for (long long p = 2; p < n; p++){
            if (isPrime[p]){
                for (long long i = p * p; (i < n) && (i >= 0); i += p){
                    if (i < 0) break;
                    isPrime[i] = false;
                }
                
                numPrimes++;
            }
        }
        
        return numPrimes;
        
    }
};


class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        
        vector<bool> isPrime(n, true);
        int numPrimes = 0, p = 2;
        
        while (p * p < n){
            if (isPrime[p]){
                for (int i = p * p; i < n; i += p){
                    isPrime[i] = false;
                }
                numPrimes++;
            }
            p++;
        }
        
        while (p < n){
            if (isPrime[p])
                numPrimes++;
            p++;
        }
        
        return numPrimes;        
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        
        vector<bool> isPrime(n, true);
        
        for (int p = 2; p * p < n; p++){
            for (int i = p * p; i < n; i += p){
                isPrime[i] = false;
            }
        }
        
        int numPrimes = 0;
        
        for (int i = 2; i < n; i++){
            if (isPrime[i])
                numPrimes++;
        }
        
        return numPrimes;
        
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p < n; p++){
            for (int i = p * 2; i < n; i += p){
                isPrime[i] = false;
            }
        }
        
        int numPrimes = 0;
        
        for (bool val : isPrime){
            if (val)
                numPrimes++;
        }
        
        return numPrimes;
        
    }
};

//1st solution using set

class Solution {
public:
    int countPrimes(int n) {
        unordered_set<int> notPrime;
        
        if (n <= 2)
            return 0;
        
        int curr = 2, numPrimes = 1;
        for (int i = curr; i < n; i += 2){
            notPrime.insert(i);
        }
        curr++;
        while (curr < n){
            if (notPrime.find(curr) == notPrime.end())
                numPrimes++;
            
            if (curr * curr >= n){
                curr++;
                continue;
            }
              
            for (int i = curr * 2; i < n; i += curr){
                notPrime.insert(i);
            }
            curr++;
        }
        return numPrimes;
        
    }
};