class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int maxFreq = 0, currFreq = 0, currVal = 0;
        
        // Inorder traversal variables
        TreeNode* node = root;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        
        while (node || !stk.empty()) {
            // Reach the leftmost node
            while (node) {
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top();
            stk.pop();
            
            // Process current node
            if (prev && node->val == prev->val) {
                currFreq++;
            } else {
                currFreq = 1;
                currVal = node->val;
            }
            
            if (currFreq > maxFreq) {
                result.clear();
                result.push_back(currVal);
                maxFreq = currFreq;
            } else if (currFreq == maxFreq) {
                result.push_back(currVal);
            }
            
            prev = node;
            node = node->right;
        }
        
        return result;
    }
};

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