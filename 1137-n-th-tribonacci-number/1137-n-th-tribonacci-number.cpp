template<std::size_t N>
constexpr std::array<uint32_t, N> generate_tribonnacci() {
    std::array<uint32_t, N> dp {};
    dp[0] = 0;
    if constexpr (N > 1) dp[1] = 1;
    if constexpr (N > 2) dp[2] = 1;
    
    for (std::size_t n = 3; n < N; ++n)
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3];

    return dp;
}

constexpr size_t TABLE_SIZE = 38;
constexpr std::array<uint32_t, TABLE_SIZE> tribonnacci_table = generate_tribonnacci<TABLE_SIZE>();




class Solution {
    std::array<int32_t, 38> _cache;
public:
    Solution() {
        _cache.fill(-1);
        _cache[0] = 0;
        _cache[1] = 1;
        _cache[2] = 1;
    }

    int tribonacci(int n) {
        return tribonnacci_table[n];
    }
    // int tribonacci(int n) {
    //     if (_cache[n] >= 0) 
    //         return _cache[n];
        
    //     int result; 
    //     if (n == 0) {
    //         result = 0;
    //     } else if (n < 3) {
    //         result = 1;
    //     } else {
    //         result = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    //     }
    //     _cache[n] = result;
    //     return _cache[n];
    // }
};