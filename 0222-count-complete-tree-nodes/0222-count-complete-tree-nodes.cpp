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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (lh == rh)
            return ( 1 << rh ) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int leftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            node = node->left;
            ++h;
        }
        return h;
    }

    int rightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            node = node->right;
            ++h;
        }
        return h;
    }
};