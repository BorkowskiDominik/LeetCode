class Solution {
    using TVI = vector<int>;
    
    void backtrack(TVI::iterator it, TVI::iterator end, TVI& current, vector<TVI>& results) {
        results.push_back(current);
        for (auto i = it; i != end; ++i) {
            current.push_back(*i);
            backtrack(i + 1, end, current, results);
            current.pop_back();
        }
    }

public:
    vector<TVI> subsets(TVI& nums) {
        vector<TVI> results;
        results.reserve(1 << nums.size());
        TVI current;
        backtrack(nums.begin(), nums.end(), current, results);
        return results;
    }
};