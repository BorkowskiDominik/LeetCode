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
    TreeNode* sortedArrayToBST(const vector<int>& nums, size_t left, size_t right) {
        if (left >= right) 
            return nullptr;
        size_t middle = left + (right - left)/2;
        TreeNode* head = new TreeNode(nums[middle]);
        head->left  = sortedArrayToBST(nums, left, middle);
        head->right = sortedArrayToBST(nums, middle+1, right);
        return head;
    }
public:

    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};