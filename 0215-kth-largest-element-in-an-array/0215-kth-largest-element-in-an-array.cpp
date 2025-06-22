enum class ALGORITHM { SET, QUEUE, NTH, MANUAL };
constexpr auto ALGO = ALGORITHM::NTH;

class Solution {
    int find_set(vector<int>& nums, int k) {
        std::multiset _set(nums.begin(), nums.end(), std::greater<int>());
        auto it = _set.begin();
        std::advance(it, k-1);
        return *it;
    }
    int find_queue(vector<int>& nums, int k) {
        std::priority_queue _queue(nums.begin(), nums.end(), std::less<int>());
        for (int i = 0; i < k -1; ++i) { _queue.pop(); }
        return _queue.top();
    }

    int find_nth(vector<int>& nums, int k) {
        auto nth = nums.begin() + (k - 1);
        std::nth_element(nums.begin(), nth, nums.end(), std::greater<int>());
        return *nth;
    }
    
    int find_manual(vector<int>& nums, int k) { 
        std::vector<int> vect(k, INT_MIN);
        for (int n : nums) {
            if (n < vect.back()) continue;
            int i = k-1;
            for (; i > 0 && vect[i-1] < n; --i )
                vect[i] = vect[i-1];
            vect[i] = n;
        }

        return vect.back();
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        if constexpr(ALGO == ALGORITHM::SET) // runtime 5%, memory: 9%
            return find_set(nums, k);
        if constexpr(ALGO == ALGORITHM::QUEUE) // runtime 44-67%, memory: 44.4%
            return find_queue(nums, k);
        if constexpr(ALGO == ALGORITHM::NTH) // runtime 98%, memory: 92% - BEST
            return find_nth(nums, k);
        if constexpr(ALGO == ALGORITHM::MANUAL) // runtime TIMEOUT (N2), memory: Y%
            return find_manual(nums, k);
        else 0;
    }
};