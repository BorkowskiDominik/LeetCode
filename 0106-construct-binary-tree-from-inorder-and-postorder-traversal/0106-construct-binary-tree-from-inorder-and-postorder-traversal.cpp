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
 // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

class Solution {
    std::unordered_map<int, int> inorder_map;
    
    struct SubtreeBounds {
        int in_begin;
        int in_end;
        int post_begin;
        int post_end;
    };

    TreeNode* buildBranch(SubtreeBounds bounds, vector<int>* postorder) {
        if (bounds.in_begin > bounds.in_end || bounds.post_begin > bounds.post_end) return nullptr;

        TreeNode* current = new TreeNode((*postorder)[bounds.post_end]);

        int center = inorder_map[current->val];
        int right_size = bounds.in_end - center;

        SubtreeBounds sub_bounds = {
            center + 1, // inorder
            center + right_size,
            bounds.post_end - right_size, // postorder
            bounds.post_end - 1
        };
        current->right = buildBranch(sub_bounds, postorder);

        sub_bounds = {
            bounds.in_begin,
            center - 1,
            bounds.post_begin,
            bounds.post_end - right_size - 1
        };
        current->left = buildBranch(sub_bounds, postorder);
        return current;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorder_map.clear();
        inorder_map.reserve(inorder.size());
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        SubtreeBounds start_bounds {
            0,
            static_cast<int>(inorder.size()-1),
            0, 
            static_cast<int>(postorder.size()-1)};
        return buildBranch(start_bounds, &postorder);
    }
};