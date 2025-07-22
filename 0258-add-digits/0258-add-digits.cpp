class Solution {
    [[maybe_unused]]
    int sumDigits(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
public:
    // int addDigits(int num) {
    //     int sum = sumDigits(num);
    //     while (sum > 9) {
    //         num = sum;
    //         sum = sumDigits(num);
    //     }
    //     return sum;
    // }
    int addDigits(int num) {
    return num == 0 ? 0 : 1 + (num - 1) % 9;
}
};