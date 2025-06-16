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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> queue;
        vector<double> result;

        int current_level = 0;
        int level_nodes = 0;
        double level_sum = 0;

        queue.push(root);
        while (!queue.empty()) {
            int level_size = queue.size();
            double sum = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = queue.front(); queue.pop();
                sum += node->val;
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            result.push_back(sum / level_size);
        }
        return result;   
    }
};