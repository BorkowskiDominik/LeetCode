class Solution {
public:
    int longestPalindrome(string s) {
        auto isOdd = [](int i){return bool(i%2);};
        std::array<int, 'z'-'A' + 1> counter {};
        for (auto l: s) {
            counter[l-'A']++;
        }
        
        bool oddUsed = false;
        int maxLength = 0;
     
        for (auto c : counter) {
            if (isOdd(c)) {
                if (!oddUsed) {
                    maxLength += c;
                    oddUsed = true;      
                } else {
                    maxLength += c / 2 * 2;
                }
            } else {
                maxLength += c;
            }
        }

        return maxLength;
    }
};