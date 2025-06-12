class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        
        std::array<int, 127> counter {};
        int left = 0, max_substr = 0;
        counter[s[left]]++;
        for (int right = 1; right < s.size(); ++right) {
            counter[s[right]]++;
            while(left < right && counter[s[right]] > 1) {
                counter[s[left]]--;
                left++;
            }         
            max_substr = std::max(max_substr, right - left + 1);
        }
        return max_substr;
    }
};