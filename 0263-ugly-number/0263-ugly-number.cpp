class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Ugly numbers are positive integers
        
        // Repeatedly divide by 2, 3, 5 as long as possible
        for (int prime : {2, 3, 5}) {
            while (n % prime == 0) {
                n /= prime;
            }
        }
        
        // If n == 1, all prime factors were 2, 3, or 5
        return n == 1;
    }
};