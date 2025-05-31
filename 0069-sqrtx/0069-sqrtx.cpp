
class Solution {
public:
    int mySqrt(int x) {
        // return int(sqrt(x)); // bruteforce
        if (x < 2)
            return x;

        int left = 1;
        int right = x / 2;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = 1LL * mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                result = mid;      // kandydat, ale może być większy
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
