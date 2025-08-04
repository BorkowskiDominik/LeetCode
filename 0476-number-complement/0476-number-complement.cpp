class Solution {
public:
    int findComplement(int num) {
        int comp = ~num;
        int mask = 0;
        while (num) {
            mask = (mask << 1) | 1;
            num >>= 1;
        }
        return comp & mask;
    }
};