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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> result;
        while(!que.empty()) {
            int level_size = que.size();
            vector<int> level;
            level.reserve(level_size);
            for (int i = 0; i < level_size; i++) {
                auto e = que.front(); que.pop();
                level.push_back(e->val);
                if (e->left) que.push(e->left);
                if (e->right) que.push(e->right);
            }
            result.push_back(std::move(level));
        }
        return result;
    }
};