class Solution {
    void ps(vector<string> vs) {
        for (auto& s: vs)
            cout << s << endl;
        cout << endl;
    }

    void backtrack(vector<vector<string>>& solutions, vector<string>& current, int n, int row,
                vector<bool>& used, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            solutions.push_back(current);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row + col;
            int d2 = row - col + n - 1;

            if (!used[col] && !diag1[d1] && !diag2[d2]) {
                current[row][col] = 'Q';
                used[col] = diag1[d1] = diag2[d2] = true;

                backtrack(solutions, current, n, row+1, used, diag1, diag2);

                used[col] = diag1[d1] = diag2[d2] = false;
                current[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        solutions.reserve(1 << n);
        vector<string> current(n, string(n, '.'));
        vector<bool> used(n, false);           // kolumny
        vector<bool> diag1(2 * n - 1, false);  // ↘ przekątne (row + col)
        vector<bool> diag2(2 * n - 1, false);  // ↙ przekątne (row - col + n - 1)

        backtrack(solutions, current, n, 0, used, diag1, diag2);
        return solutions;
    }
};