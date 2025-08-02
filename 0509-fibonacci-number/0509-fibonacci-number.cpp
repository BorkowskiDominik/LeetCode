constexpr int PRECALC_SIZE = 31;
constexpr std::array<int, PRECALC_SIZE> FIBO = [](){
    std::array<int, PRECALC_SIZE> res;
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i < PRECALC_SIZE; ++i) {
        res[i] = res[i-1] + res[i-2];
    }
    return res;
}();

class Solution {
    std::unordered_map<int, int> _cache;
    
    int _fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (!_cache.contains(n))
            _cache[n] = _fib(n-1) + _fib(n-2);
        return _cache[n];
    }

public:
    int fib(int n) {
        if (n < FIBO.size())
            return FIBO[n];
        return _fib(n);
    }
};