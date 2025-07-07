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
    void traverse(TreeNode* node, vector<int>& solution) {
        if (!node) return;
        traverse(node->left, solution);
        solution.push_back(node->val);
        traverse(node->right, solution);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> solution;
        traverse(root, solution);
        return solution;
    }
};