class Solution {
    using TVI = vector<int>;
    using TVVI = vector<vector<int>>;
    using PTVII = std::pair<TVI, int>;

    void find_combinations(
        const TVI& candidates,
        const int target,
        const int start_idx,
        PTVII& current,
        TVVI& combinations
    ) {
        if (current.second == target) {
            combinations.push_back(current.first);
            return; 
        }
        for (int i = start_idx; i < candidates.size(); ++i) {
            auto& candidate = candidates[i];
            if (current.second + candidate > target) return;
            current.first.push_back(candidate);
            current.second += candidate;

            find_combinations(candidates, 
                target,
                i,
                current,
                combinations);

            current.first.pop_back();
            current.second -= candidate;
        }
    }
public:
    TVVI combinationSum(TVI& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        TVVI combinations;
        PTVII current {{}, 0}; // pair of current combination and the current sum
        int start_idx = 0;
        find_combinations(candidates, target, start_idx, current, combinations);
        return combinations;
    }
};