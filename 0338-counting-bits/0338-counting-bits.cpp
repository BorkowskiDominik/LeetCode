class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.reserve(n+1);
        bitset<17> bs;
        for (int i = 0; i <= n; ++i) {
            bs = i;
            result.push_back(bs.count());
        }
        return result;
    }
};


// low level version:
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> result(n + 1);
//         for (int i = 1; i <= n; ++i)
//             result[i] = result[i >> 1] + (i & 1);
//         return result;
//     }
// };
