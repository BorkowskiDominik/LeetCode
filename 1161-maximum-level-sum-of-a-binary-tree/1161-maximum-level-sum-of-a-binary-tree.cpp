class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        std::pair<int, int> result {0, INT_MIN}; // pair : level, maxSum

        while(!q.empty()) {
            int level_size = q.size();
            level++;
            int level_sum = 0;
            for (int i = 0; i < level_size; ++i) {
                auto* node = q.front(); q.pop();
                level_sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level_sum > result.second)
                result = {level, level_sum};
        }

        return result.first;
    }
};


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