class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        // Min heap: najmniej popularny element na górze
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto& [num, freq] : count) {
            minHeap.emplace(freq, num);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        result.reserve(k);
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
