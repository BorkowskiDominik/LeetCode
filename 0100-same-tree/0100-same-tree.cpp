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
    // recursive
    bool isSameTree_recursive(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // iterative
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp, qq;
        qp.push(p);
        qq.push(q);

        while (!qp.empty() && !qq.empty()) {
            TreeNode* n1 = qp.front(); qp.pop();
            TreeNode* n2 = qq.front(); qq.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;

            qp.push(n1->left);
            qp.push(n1->right);
            qq.push(n2->left);
            qq.push(n2->right);
        }

        return qp.empty() && qq.empty();
    }
};