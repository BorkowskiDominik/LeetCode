/*
NOTE:
If we will update kth element frequently we can consider creating some additional indexing.
For exampe store information how many element are on the left so we imidietly know if we should
should search element in left or right branch.

Or even creating more indexes, but it would require more complex caching. For example store every tenth element
*/

class Solution {
    int result;
public:
    void inorder(TreeNode* root, int k, int& counter) {
        if (!root || counter >= k) return;
        // visit left
        inorder(root->left, k, counter);
        // visit node
        counter++;
        if (counter == k) {
            result = root->val;
            return;
        }
        // visit right
        inorder(root->right, k, counter);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter{};
        inorder(root, k, counter);
        return result;
    }
};