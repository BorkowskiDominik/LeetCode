class Solution {
    void dfs(TreeNode* root, std::optional<int>& prev, bool& valid) {
        if (!root || !valid) return;
        
        // visit left
        dfs(root->left, prev, valid);
        
        // visit node
        if (prev && *prev >= root->val){
            valid = false;
        }
        prev = root->val;
        
        // visit right
        dfs(root->right, prev, valid);
    }
public:
    bool isValidBST(TreeNode* root) {
        std::optional<int> prev;
        bool valid = true;
        dfs(root, prev, valid);
        return valid;
    }
};