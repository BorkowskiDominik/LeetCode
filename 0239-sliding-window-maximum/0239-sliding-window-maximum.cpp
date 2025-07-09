class Solution {
public:
    // monotinic queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(nums.size()-k+1);
        deque<int> dq; // will store indices

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices outside the window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements in the back
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }

    vector<int> maxSlidingWindowFirstAttempt(vector<int>& nums, int k) {
        vector<int> maxes;
        multiset<int, std::greater<int>> window(nums.begin(), nums.begin()+k);
        maxes.push_back(*window.begin());

        for (int i = 0; i+k < nums.size(); ++i) {
            auto old_num = nums[i];
            auto new_num = nums[i+k];
            if (old_num == new_num) {
                maxes.push_back(maxes.back());
                continue;
            }
            window.erase(window.find(old_num));
            window.insert(new_num);
            maxes.push_back(*window.begin());
        }

        return maxes;
    }
};