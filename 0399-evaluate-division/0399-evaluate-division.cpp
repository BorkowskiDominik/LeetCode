struct Node {
    std::string id;
    std::vector<std::pair<std::string, double>> neighbors;
};

class Solution {
    template<typename T>
    using TVV = vector<vector<T>>;
    
    template<typename T>
    using TV = vector<T>;

    unordered_map<std::string, Node> generate_graph(TVV<string>& equations, TV<double>& values) {
        unordered_map<std::string, Node> graph_map {};
        for (int i = 0; i < equations.size(); ++i) {
            const auto& numerator = equations[i][0];
            const auto& denominator = equations[i][1];
            if (!graph_map.contains(numerator)) graph_map[numerator] = Node {numerator, {}};
            if (!graph_map.contains(denominator)) graph_map[denominator] = Node {denominator, {}};
            graph_map[numerator].neighbors.push_back({denominator,  values[i]});
            graph_map[denominator].neighbors.push_back({numerator, 1 / values[i]});
        }
        return graph_map;
    }

    [[maybe_unused]]
    bool dfs(const std::string& start,
            const std::string& end,
            const unordered_map<std::string, Node>& graph_map,
            std::unordered_set<std::string>& visited,
            double& factor) {
        if (start == end) return true;
        visited.insert(start);
        for (const auto&[id, cost] : graph_map.at(start).neighbors) {
            if (visited.contains(id)) continue;
            factor *= cost;
            if (dfs(id, end, graph_map, visited, factor)) return true;
            factor /= cost;
        }
        visited.erase(start);
        return false;
    }

    [[maybe_unused]]
    bool bfs(const std::string& start,
            const std::string& end,
            const unordered_map<std::string, Node>& graph_map,
            std::unordered_set<std::string>& visited,
            double& factor) {

        std::queue<std::pair<std::string, double>> bfs_que;
        bfs_que.emplace(start, 1.0);
        visited.insert(start);
        while (!bfs_que.empty()) {
            auto [current, value] = bfs_que.front(); bfs_que.pop();
            for (const auto& [neighbor, weight] : graph_map.at(current).neighbors) {
                if (visited.contains(neighbor)) continue;
                factor = value * weight;
                if (neighbor == end) return true;
                bfs_que.emplace(neighbor, factor);
                visited.insert(neighbor);
            }
        }
        return false;
    }

    double evaluate(const TV<string>& query, const unordered_map<std::string, Node>& graph_map) {
        if (!graph_map.contains(query[0]) || !graph_map.contains(query[1])) return -1;
        double result = 1;
        if (query[0] == query[1]) return 1.0;
        std::unordered_set<std::string> visited {};
        // if (!dfs(query[0], query[1], graph_map, visited, result)) return -1;
        if (!bfs(query[0], query[1], graph_map, visited, result)) return -1;
        return result;
    }

public:
    TV<double> calcEquation(TVV<string>& equations, TV<double>& values, TVV<string>& queries) {
        TV<double> results {};
        results.reserve(queries.size());
        const auto graph_map = generate_graph(equations, values);
        for (const auto& query : queries) {
            results.push_back(evaluate(query, graph_map));
        }
        return results;
    }
};