/*Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class Solution {
public:
    static int primesLessThan100[] = {7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    bool isPrime(int num){
        if (num % 2 == 0 || num % 5 == 0)
            return false;
        int divBy3 = 0;
        while(num >= 0){
            divBy3 += num%10;
            num /= 10;
        }
        if(divBy3 % 3 == 0)
            return false;
        double result = sqrt(double(num));
        int res = int(result);
        cout << "res is " << res << endl;
        for(int i : primesLessThan100){
            if (i > res)
                break;
            if (num % i == 0)
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        if (n == 3)
            return 1;
        int numOfPrimes = 2;
        for (int i = 1; i < n; i++){ //will never get close to n. ok to reduce this way?
            int low = (6 * i) - 1;
            int high = low + 2;
            cout << low << endl << high << endl;
            if (low < n){
                if(isPrime(low))
                    numOfPrimes++;
            }
            if (high < n){
                if(isPrime(high))
                    numOfPrimes++;
            }
            if (low >= n || high >= n)
                break;
        }
        return numOfPrimes;
    }
};