class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<sizeof(int)*8> bits(n);
        if (n >= 0) return bits.count() == 1;
        return false;
    }
};