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
    void getLeafs(TreeNode* node, std::vector<int>& leafs) {
        if (!node) return;
        if (!node->left && !node->right) {
            leafs.push_back(node->val);
            return;
        }
        getLeafs(node->left, leafs);
        getLeafs(node->right, leafs);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);
        return leafs1 == leafs2;
    }
};