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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0; 
        std::vector<std::pair<TreeNode*, int>> node_stack;
        int total_sum{};
        node_stack.reserve(10);
        node_stack.push_back({root, 0});
        
        while (!node_stack.empty()) {
            auto [el, branch_sum] = node_stack.back(); node_stack.pop_back();
            branch_sum = branch_sum * 10 + el->val;
            
            if (el->left)
                node_stack.push_back({el->left, branch_sum});
            
            if (el->right)
                node_stack.push_back({el->right, branch_sum});
            
            if (!el->left && !el->right) {
                total_sum += branch_sum;
            }
        }
        return total_sum;
    }
};