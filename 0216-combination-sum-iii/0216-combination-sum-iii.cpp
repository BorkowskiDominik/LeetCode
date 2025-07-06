class Solution {
    void build_combinations(int start, int k, int n, vector<int>&current, vector<vector<int>>& solutions) {
        if (k == 0 && n == 0) {
            solutions.push_back(current);
            return;    
        }

        if (n == 0 || k <= 0 || n < k)
            return;

        for (int i = start + 1; i <= std::min(n, 9); ++i) {
            current.push_back(i);
            build_combinations(i, k - 1, n-i, current, solutions);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if ( k > 9 || n > 45 || n < k) return {};
        
        vector<vector<int>> solutions;
        vector<int> current;
        current.reserve(k);

        build_combinations(0, k, n, current, solutions);
        return solutions;
    }
};