
class Solution {
    TreeNode*& findRef(TreeNode*& node, int key) {
        if (!node || node->val == key) return node;
        if (key < node->val) return findRef(node->left, key);
        else return findRef(node->right, key);
    }

    void insertSubtree(TreeNode*& into, TreeNode* what) {
        if (!what) return;
        decltype(auto) parent = findRef(into, what->val);
        parent = what;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*& nodeRef = findRef(root, key);
        if (!nodeRef) return root;

        TreeNode* toDelete = nodeRef;
        if (!toDelete->right) {
            nodeRef = toDelete->left;
        } else {
            TreeNode* replacement = toDelete->right;
            insertSubtree(replacement, toDelete->left);
            nodeRef = replacement;
        }
        delete toDelete;
        return root;
    }
};