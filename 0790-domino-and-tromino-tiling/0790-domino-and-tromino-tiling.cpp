constexpr int MOD = 1'000'000'007;

template<size_t SIZE>
constexpr std::array<int, SIZE> GEN_ARRAY() {
    std::array<int, SIZE> array;
    if (SIZE > 0) array[0] = 1;
    if (SIZE > 1) array[1] = 1;
    if (SIZE > 2) array[2] = 2;
    for (int i = 3; i < SIZE; ++i) {
        array[i] = (2LL*array[i-1] + array[i-3])%MOD;
    }
    return array;
}

constexpr size_t MAX_N = 1000;
constexpr auto TILINGS = GEN_ARRAY<MAX_N+1>();

class Solution {
public:
    int numTilings(int n) {
        return TILINGS[n];
    }
};