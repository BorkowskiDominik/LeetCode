class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        projects.reserve(n);

        for (int i = 0; i < n; ++i)
            projects.emplace_back(capital[i], profits[i]);
        
        sort(projects.begin(), projects.end());

        priority_queue<int> available;
        int idx = 0;
        while (k--) {
            while (idx < n && projects[idx].first <= w) {
                available.push(projects[idx].second);
                ++idx;
            }
            if (available.empty()) break;
            w += available.top(); available.pop();
        }

        return w;
    }

};