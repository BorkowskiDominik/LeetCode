class Solution {
    unordered_map<char, int> ROME_TO_INT {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int result = 0;
        int maxSeen = 0;

        for(int i = s.size()-1; i >= 0; --i)
        {            
            int value = ROME_TO_INT[s[i]];
            if (value < maxSeen)
                result -= value;
            else {
                result += value;
                maxSeen = value;
            }
        }
        return result;
    }
};