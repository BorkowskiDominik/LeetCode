class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (const auto& p : prerequisites) {
            int to = p[0], from = p[1];
            adj[from].push_back(to);
            ++indegree[to];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0) q.push(i);

        int visited = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++visited;
            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return visited == numCourses;
    }
};
