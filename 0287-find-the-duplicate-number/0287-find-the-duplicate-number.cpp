class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100'001> bs;
        for (auto num: nums){
            if (bs[num]) return num;
            bs.set(num);
        }
        return 0;
    }
};