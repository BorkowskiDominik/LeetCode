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

#define FAST

class Solution {
    static constexpr int OFFSET = 3000;
#ifdef FAST
        std::vector<int> inorder_index;
#else
        unordered_map<int, int> inorder_map;
#endif
    struct SubtreeBounds {
        size_t pre_begin;
        size_t pre_end;
        size_t in_begin;
        size_t in_end;
    };

public:
    #ifdef FAST        
        Solution() : inorder_index(6001, -1) {}
    #endif

    TreeNode* buildTree(SubtreeBounds idx, const vector<int>* p_preorder) {
        if (idx.pre_begin > idx.pre_end || idx.in_begin > idx.in_end) 
            return nullptr;

        size_t rootVal = (*p_preorder)[idx.pre_begin];
        
        TreeNode* root = new TreeNode(rootVal);
#ifdef FAST
        size_t inRootIndex = inorder_index[rootVal + OFFSET];
#else
        size_t inRootIndex = inorder_map[rootVal];
#endif
        size_t leftSize = inRootIndex - idx.in_begin;

        root->left = buildTree({idx.pre_begin + 1, idx.pre_begin + leftSize, idx.in_begin, inRootIndex - 1}, p_preorder);
        root->right = buildTree({idx.pre_begin + leftSize + 1, idx.pre_end, inRootIndex +1, idx.in_end}, p_preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
#ifdef FAST
    for (int i = 0; i < inorder.size(); ++i) {
        inorder_index[inorder[i] + OFFSET] = i;
    }
#else
        inorder_map.clear();
        inorder_map.reserve(inorder.size());
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
#endif
        auto result = buildTree({0, preorder.size() - 1, 0, inorder.size() - 1}, &preorder);
        return result;
    }
};