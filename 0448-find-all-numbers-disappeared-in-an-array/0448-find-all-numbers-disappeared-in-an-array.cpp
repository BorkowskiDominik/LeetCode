class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing;
        missing.resize(nums.size()+1);
        for (int i = 0; i < missing.size(); ++i)
            missing[i] = i;
        for (auto n : nums) {
            missing[n] = 0;
        }
        std::erase_if(missing, [](int i){return !i;});
        return missing;
    }
};