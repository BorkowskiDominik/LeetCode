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
    int check(TreeNode* node) {
        if (!node) return 0;

        int left = check(node->left);
        if (left == -1) return -1; // lewy niezrównoważony

        int right = check(node->right);
        if (right == -1) return -1; // prawy niezrównoważony

        if (std::abs(left - right) > 1) return -1; // aktualny niezrównoważony

        return std::max(left, right) + 1; // zwróć wysokość
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};


// class Solution {
//     int depth(TreeNode* node) {
//         if (!node) return 0;
//         return std::max(depth(node->left), depth(node->right)) + 1;
//     }

// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;
//         if (abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right))
//             return true;
//         return false;
//     }
// };