class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bit_counter {};
        while( a || b || c) {
            if ( c & 1) {
                if((b&1) == 0 && (a&1) == 0) {
                    ++bit_counter;
                }
            } else {
                bit_counter += (a&1) + (b&1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return bit_counter;
    }
};