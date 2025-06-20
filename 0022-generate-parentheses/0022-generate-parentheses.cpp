class Solution {
public:
    void generate_combinations(const int n, 
        const int used_open,
        const int used_closed,
        string& current,
        vector<string>& combinations
    ) {
        if (current.size() == 2*n) {
            combinations.push_back(current);
            return;
        }
        if (used_open < n) {
            current.push_back('(');
            generate_combinations(n , used_open+1, used_closed, current, combinations);
            current.pop_back();
        }
        if (used_open > used_closed) {
            current.push_back(')');
            generate_combinations(n , used_open, used_closed+1, current, combinations);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        string current; 
        current.reserve(2*n);
        generate_combinations(n, 0, 0, current, combinations);
        return combinations;
    }
};