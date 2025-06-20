class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back();
        }
    }

    size_t fact(size_t k) {
        static unordered_map<size_t, size_t> cache;
        if (cache.contains(k)) return cache[k];
        if (k < 2) return 1;
        cache[k] = fact(k-1) * k;
        return cache[k];
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        result.reserve( fact(static_cast<size_t>(n)) /( fact(static_cast<size_t>(k)) * fact(static_cast<size_t>(n-k)) ) );
        vector<int> current;
        current.reserve(k);
        backtrack(1, n, k, current, result);
        return result;
    }
};