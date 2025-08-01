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
    int sumLeft(TreeNode* node, bool isLeft) {
        auto isLeaf = [](TreeNode* node) { return !node->left && !node->right; };
        if (!node) return 0;
        if (isLeaf(node)) {
            if (isLeft)
                return node->val;
            return 0;
        }
        return sumLeft(node->left, true) + sumLeft(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumLeft(root->left, true) + sumLeft(root->right, false);
    }
};