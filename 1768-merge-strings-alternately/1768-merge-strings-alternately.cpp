class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
       
        const auto w1_size = word1.size(), w2_size = word2.size();
        result.reserve(w1_size + w2_size);
        
        for (int i = 0; i < std::min(w1_size, w2_size); ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }

        // handle tails if any
        if (w1_size > w2_size) {
            result.append(word1.substr(w2_size));
        } else if (w1_size < w2_size) {
            result.append(word2.substr(w1_size));
        }
        
        return result;
    }
};