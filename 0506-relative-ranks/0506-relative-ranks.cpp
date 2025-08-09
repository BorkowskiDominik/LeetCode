constexpr std::array<const char*, 3> PODIUM {
            "Gold Medal",
            "Silver Medal",
            "Bronze Medal"
        };


class Solution {
    string position_to_str(int i) {
        if (i <= 0) return "-1";
        if (i > 3) return to_string(i);
        return PODIUM[i-1];
    }

public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ranks;
        ranks.resize(score.size());
        
        std::vector<int> priority;
        priority.reserve(score.size());

        for (int i = 0; i < score.size(); ++i) {
            priority.push_back(i);
        }
        std::sort(
            priority.begin(),
            priority.end(),
            [&score](int a, int b){
                return score[a] > score[b];
            }
        );
        for (int i = 0; i < priority.size(); ++i) {
            ranks[priority[i]] = position_to_str(i+1);
        }
        return ranks;
    }
};