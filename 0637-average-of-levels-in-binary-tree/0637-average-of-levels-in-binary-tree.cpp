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
    std::queue<std::pair<TreeNode*, int>> _queue;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> result;

        int current_level = 0;
        int level_nodes = 0;
        double level_sum = 0;
        _queue.push({root, current_level});
        while(!_queue.empty()) {
            auto [node, level] = _queue.front(); _queue.pop();
            if (!node) continue;
            if (level != current_level) {
                result.push_back(level_sum / level_nodes);
                level_nodes = 0;
                level_sum = 0;
                current_level = level;
            }
            level_sum += node->val;
            level_nodes++;
            _queue.push({node->left, current_level+1});
            _queue.push({node->right, current_level+1});
        }
        result.push_back(level_sum / level_nodes);
        return result;   
    }
};