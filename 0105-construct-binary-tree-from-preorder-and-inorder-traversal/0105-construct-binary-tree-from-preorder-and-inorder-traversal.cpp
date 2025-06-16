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
    unordered_map<int, int> inorder_map;

    struct SubtreeBounds {
        size_t pre_begin;
        size_t pre_end;
        size_t in_begin;
        size_t in_end;
    };

public:
    TreeNode* buildTree(SubtreeBounds idx, const vector<int>* preorder) {
        if (idx.pre_begin > idx.pre_end || idx.in_begin > idx.in_end) 
            return nullptr;

        size_t rootVal = (*preorder)[idx.pre_begin];
        
        TreeNode* root = new TreeNode(rootVal);
        size_t inRootIndex = inorder_map[rootVal];
        size_t leftSize = inRootIndex - idx.in_begin;

        root->left = buildTree({idx.pre_begin + 1, idx.pre_begin + leftSize, idx.in_begin, inRootIndex - 1}, preorder);
        root->right = buildTree({idx.pre_begin + leftSize + 1, idx.pre_end, inRootIndex +1, idx.in_end}, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        inorder_map.reserve(inorder.size());
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        auto result = buildTree({0, preorder.size() - 1, 0, inorder.size() - 1}, &preorder);
        return result;
    }
};