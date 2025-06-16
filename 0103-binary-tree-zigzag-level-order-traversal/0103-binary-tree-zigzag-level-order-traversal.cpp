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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        std::deque<TreeNode*> que;
        que.push_back(root);
        vector<vector<int>> result;
        bool left_to_right = true;
        while(!que.empty()) {
            int level_size = que.size();
            vector<int> level;
            level.reserve(level_size); 

            for (int i = 0; i < level_size; ++i){
                auto node = left_to_right ? que.front() : que.back();
                if (left_to_right) que.pop_front(); else que.pop_back();

                level.push_back(node->val);

                if (left_to_right) {
                    if (node->left) que.push_back(node->left);
                    if (node->right) que.push_back(node->right);
                } else {
                    if (node->right) que.push_front(node->right);
                    if (node->left) que.push_front(node->left);
                }
            }
            result.push_back(std::move(level));
            left_to_right = !left_to_right;
        }
        return result;
    }
};