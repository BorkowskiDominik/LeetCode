class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<sizeof(int)*8> bits(n);
        if (n > 0) return bits.count() == 1;
        return false;

        // alternative solution without conversion to bitset
        //return n > 0 && (n & (n - 1)) == 0;
    }
};