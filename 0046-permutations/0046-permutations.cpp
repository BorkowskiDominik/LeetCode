enum class METHOD {STD, BACKTRACK};
constexpr METHOD ALGO = METHOD::BACKTRACK;

class Solution {
    using TVI = vector<int>;
    using TVVI =vector<TVI>;

    [[maybe_unused]]
    void print (const TVI& v){
        for (const auto& e : v)
            cout << e << " ";
        cout << endl;
    };

public:
    TVVI permute_std(TVI& nums) {
        std::sort(nums.begin(), nums.end());
        TVVI result;
        result.push_back(nums);
        while(std::next_permutation(nums.begin(), nums.end())) {
            result.push_back(nums);
        }
        return result;
    }

    void backtrack(const TVI& nums, std::vector<bool>& used, TVI& current, TVVI& results) {
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            
            backtrack(nums, used, current, results);
            
            current.pop_back();
            used[i] = false;
        }
    }

    TVVI permute_backtrack(TVI& nums) {
        TVVI results;
        TVI current;
        current.reserve(nums.size());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, results);
        return results;
    }

    TVVI permute(TVI& nums) {
        if constexpr(ALGO == METHOD::STD)
            return permute_std(nums);
        else if constexpr(ALGO == METHOD::BACKTRACK)
            return permute_backtrack(nums);
        else 
            return {};
    }
};