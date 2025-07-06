class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        // Tworzymy pary (nums2[i], nums1[i]) i sortujemy malejąco po nums2[i]
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        std::sort(pairs.rbegin(), pairs.rend()); // sort malejący po nums2
        vector<int> base;
        base.reserve(n);  // Rezerwujemy pamięć z wyprzedzeniem

        priority_queue<int, vector<int>, greater<int>> minHeap(
            greater<int>(), std::move(base)
        ); // kopiec min na nums1

        long long sum = 0;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            int currNum2 = pairs[i].first;
            int currNum1 = pairs[i].second;

            minHeap.push(currNum1);
            sum += currNum1;

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                result = max(result, sum * (long long)currNum2);
            }
        }

        return result;
    }
};
