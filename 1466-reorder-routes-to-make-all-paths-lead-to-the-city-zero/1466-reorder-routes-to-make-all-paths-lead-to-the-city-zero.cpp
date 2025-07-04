class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);  // {dest, needs_reversal}

        for (const auto& c : connections) {
            graph[c[0]].emplace_back(c[1], true);   // edge goes from c[0] -> c[1], may need reversal
            graph[c[1]].emplace_back(c[0], false);  // back edge, doesn't need reversal
        }

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int swaps = 0;

        while (!q.empty()) {
            int city = q.front(); q.pop();

            for (auto& [neighbor, needs_reversal] : graph[city]) {
                if (!visited[neighbor]) {
                    swaps += needs_reversal;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return swaps;
    }
};
