// this is Leventein Algorithm/Distance problem
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size())
            std::swap(word1, word2); // zapewniamy, że word1 jest większy => mniej pamięci

        int m = word1.size(), n = word2.size();
        std::vector<int> prev(n + 1), curr(n + 1);

        for (int j = 0; j <= n; ++j) prev[j] = j;

        for (int i = 1; i <= m; ++i) {
            curr[0] = i;
            for (int j = 1; j <= n; ++j) {
                int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                curr[j] = std::min({ 
                    prev[j] + 1,        // usunięcie
                    curr[j - 1] + 1,    // wstawienie
                    prev[j - 1] + cost  // zamiana
                });
            }
            std::swap(prev, curr);
        }

        return prev[n];
    }
};
