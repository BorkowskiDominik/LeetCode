class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        bitset<1001> occurences;

        for (auto a: arr)
            ++counter[a];
        
        for (auto& [_, count] : counter) {
            if (occurences.test(count))
                return false;
            occurences.set(count);
        }
        return true;
    }
};