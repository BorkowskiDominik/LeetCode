class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) return res;

        using T = tuple<int, int, int>;
        auto cmp = [](const T& a, const T& b) {
            return get<0>(a) > get<0>(b);
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        for (int j = 0; j < nums2.size() && j < k; ++j) {
            pq.emplace(nums1[0] + nums2[j], 0, j);
        }

        while (!pq.empty() && res.size() < k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size()) {
                pq.emplace(nums1[i + 1] + nums2[j], i + 1, j);
            }
        }

        return res;
    }
};
