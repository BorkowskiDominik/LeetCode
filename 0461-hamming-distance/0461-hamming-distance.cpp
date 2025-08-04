class Solution {
public:
    int hammingDistance(int x, int y) {
        // return std::bitset<sizeof(int)*8>(x^y).count();
        //C++ 20:
        return std::popcount(static_cast<unsigned int>(x ^ y));
    }
};