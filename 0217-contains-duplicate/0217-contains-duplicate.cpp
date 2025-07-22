class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto it = std::unique(nums.begin(), nums.end());
        return it != nums.end();
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         std::unordered_set<int> seen;
//         for (int n : nums) {
//             if (!seen.insert(n).second) return true;
//         }
//         return false;
//     }
// };
