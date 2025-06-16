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
    std::vector<TreeNode*> in_order;
public:
    Solution(){
        in_order.reserve(2000);
    }

    void place_in_order(TreeNode* node) {
        if (node) {
            in_order.push_back(node);
            place_in_order(node->left);            
            place_in_order(node->right);
        }
    }

    void fix_linking() {
        if (in_order.empty()) return;
        for (int i = 0; i < in_order.size() - 1; i++) {
            in_order[i]->left = nullptr;
            in_order[i]->right = in_order[i+1];
        }
        in_order.back()->left = nullptr;
        in_order.back()->right = nullptr;
    }

    void flatten(TreeNode* root) {
        place_in_order(root);
        fix_linking();
    }
};