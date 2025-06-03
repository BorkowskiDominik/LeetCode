class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(const auto& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }
        
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [_, group]: groups) {
            result.push_back(std::move(group));
        }
        return result;
    }
};