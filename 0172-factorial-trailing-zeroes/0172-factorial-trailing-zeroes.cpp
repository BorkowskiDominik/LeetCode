class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 2)
            return 0;
        int count = 0;
        for (int i = 5; (n / i) >= 1; i*=5) {
            count += n / i;
        }
        return count;
    }
};