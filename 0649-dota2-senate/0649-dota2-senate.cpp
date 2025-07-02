class Solution {
    static const unordered_map<char, std::string> NAME;
public:
    string predictPartyVictory(string senate) {
        const int senat_size = senate.size();
        if (senat_size == 1) return NAME.at(senate[0]);

        std::queue<int> radiant, dire;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        while(!radiant.empty() && !dire.empty()) {
            auto r = radiant.front(); radiant.pop();
            auto d = dire.front(); dire.pop();
            if (r < d) {
                radiant.push(r+senat_size);
            } else {
                dire.push(d+senat_size);
            }
        }

        return NAME.at(radiant.empty() ? 'D' : 'R');
    }
};

const unordered_map<char, std::string> Solution::NAME = {{'R', "Radiant"}, {'D', "Dire"}};