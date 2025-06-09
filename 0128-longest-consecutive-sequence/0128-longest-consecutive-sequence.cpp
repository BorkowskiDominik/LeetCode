class Solution {
public:
    int longestConsecutive_(vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;

        for (int num : nums) {
            // tylko jeśli to początek sekwencji
            if (!num_set.count(num - 1)) {
                int current = num;
                int length = 1;

                while (num_set.count(current + 1)) {
                    current++;
                    length++;
                }

                max_len = std::max(max_len, length);
            }
        }

        return max_len;
    }
    int longestConsecutive(vector<int> &arr) {
    unordered_set<int> st;
    int res = 0;

    // Hash all the array elements
    for (int val: arr)
        st.insert(val);

    // check each possible sequence from the start then update optimal length
    for (int val: arr) {
      
        // if current element is the starting element of a sequence
        if (st.find(val) != st.end() && st.find(val-1) == st.end()) {
          
            // Then check for next elements in the sequence
            int cur = val, cnt = 0;
            while (st.find(cur) != st.end()) {
                
                // Remove this number to avoid recomputation
                st.erase(cur);
                cur++;
              	cnt++;
            }

            // update  optimal length
            res = max(res, cnt);
        }
    }
    return res;
}
};
