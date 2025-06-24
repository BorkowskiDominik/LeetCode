class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> order;
        order.reserve(numCourses);
        
        for (const auto& p: prerequisites) {
            int from = p[1], to = p[0];
            ++indegree[to];
            adj[from].push_back(to);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0) q.push(i);
        
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int e = q.front(); q.pop();
            order.push_back(e);
            for (auto n: adj[e]) {
                if (--indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        if (visited != numCourses) return {};
        return order;
    }
};