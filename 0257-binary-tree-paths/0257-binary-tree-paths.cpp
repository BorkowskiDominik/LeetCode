/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void flush (vector<string>& solutions, vector<int>& current) {
        string solution;
        solution.reserve(current.size()*6);
        for (int i = 0; i < current.size()-1; ++i) {
            solution += to_string(current[i]);
            solution += "->";
        }
        solution += to_string(current.back());
        solutions.push_back(solution);
    }

    void dfs (TreeNode* node, vector<string>& solutions, vector<int>& current) {
        if (!node) return;
        current.push_back(node->val);
        if (node->left || node->right) {
            dfs(node->left, solutions, current);
            dfs(node->right, solutions, current);
        } else {
            flush(solutions, current);
        }
        current.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> solutions; 
        solutions.reserve(32);
        vector<int> current;
        current.reserve(100);
        dfs(root, solutions, current);
        return solutions;
    }
};