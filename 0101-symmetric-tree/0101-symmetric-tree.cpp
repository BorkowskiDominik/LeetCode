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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> lq;
        lq.push(root->left);
        lq.push(root->right);

        while(!lq.empty()) {
            TreeNode* l = lq.front(); lq.pop();
            TreeNode* r = lq.front(); lq.pop();
            if ((l && !r)||(!l && r)) return false;
            if (!l && !r) continue;
            if (l->val != r->val) return false;
            lq.push(l->right);
            lq.push(r->left);
            lq.push(l->left);
            lq.push(r->right);
        }
        return lq.empty();
    }
};