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
    int count_good(TreeNode* node, int maxVisited) {
        if (!node) return 0;
        int isGood = (maxVisited > node->val) ? 0 : 1;
        maxVisited = std::max(maxVisited, node->val);
        return count_good(node->left, maxVisited) + count_good(node->right, maxVisited) + isGood;
    }
public:
    int goodNodes(TreeNode* root) {
        return count_good(root, root->val);
    }
};