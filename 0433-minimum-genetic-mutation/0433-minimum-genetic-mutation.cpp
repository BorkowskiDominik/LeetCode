[[maybe_unused]]
ostream& operator<<(ostream& o, const unordered_map<string, unordered_set<string>>& graph) {
    for (const auto& [key, s] : graph) {
        cout << "k:" << key << " v:";
        for (const auto& e : s) {
            cout << " " << e;
        }
        cout << endl;
    }
    return o;
}

constexpr int NO_RESULT = -1;

class Solution {
    using TGraphMap = unordered_map<string, unordered_set<string>>;
public:
    int count_differences(const string& s1, const string& s2) {
        int diffs {};
        for (int i = 0; i < s1.size(); ++i ) {
            if (s1[i] != s2[i]) ++diffs;
            if (diffs > 1) return diffs;
        }
        return diffs;
    }

    TGraphMap build_map(const vector<string>& bank) {
        unordered_map<string, std::unordered_set<string>> graph_map;
        for (int i = 0; i < bank.size(); ++i) {            
            const auto& s1 = bank[i];
            graph_map.try_emplace(s1);
            for (int j = i+1; j < bank.size(); ++j) {
                const auto& s2 = bank[j];
                if (count_differences(s1, s2) != 1) continue;
                graph_map[s1].insert(s2);
                graph_map[s2].insert(s1);
            }
        }
        return graph_map;
    }

    int bfs(const string& startGene, const string& endGene, const TGraphMap& graph) {
        std::queue<string> bfs_queue;
        std::unordered_set<std::string> visited;
        bfs_queue.push(startGene);
        int cnt = 0;
        while (!bfs_queue.empty()) {
            int size = bfs_queue.size();
            for (int i = 0; i < size; ++i) {
                const auto el = bfs_queue.front(); bfs_queue.pop();
                visited.insert(el);
                if (el == endGene) return cnt;
                for (const auto& n : graph.at(el)) {
                    if (visited.contains(n)) continue;
                    bfs_queue.push(n);
                }
            }
            ++cnt;
        }
        return NO_RESULT;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;
        bank.push_back(startGene);
        auto graph_map = build_map(bank);
        assert(graph_map.size());
        // cout << graph_map << endl;
        if (!graph_map.contains(startGene) || !graph_map.contains(endGene)) return NO_RESULT;
        return bfs(startGene, endGene, graph_map);
    }
};