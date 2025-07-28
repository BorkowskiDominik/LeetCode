class Solution {
public:
    int divide(int dividend, int divisor) {
        // Obsługa overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Konwersja na long long, żeby uniknąć overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        if ((dividend > 0) ^ (divisor > 0))
            result = -result;

        return result;
    }
};
