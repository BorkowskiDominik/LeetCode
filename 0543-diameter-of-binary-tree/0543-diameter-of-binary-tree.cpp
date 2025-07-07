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
    int depth(TreeNode* node, int& maxDepth) {
        if (!node)
            return 0;
        auto left = depth(node->left, maxDepth);
        auto right = depth(node->right, maxDepth);
        maxDepth = std::max(maxDepth, left + right);

        return max(left, right) + 1; // return max tree depth
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = 0;
        depth(root, maxDepth);
        return maxDepth;
    }
};