enum class ALGORITHM {FIRST};
constexpr auto ALGO = ALGORITHM::FIRST;

class Solution {
    void findTargetSum(TreeNode* node, const int targetSum, vector<int>& path, int& counter);
    int pathSumMain(TreeNode* root, int targetSum);

public:
    int pathSum(TreeNode* root, int targetSum) {
        if constexpr(ALGO == ALGORITHM::FIRST)
            return pathSumMain(root, targetSum);
        return 0; // Unknown algorithm
    }
};


void Solution::findTargetSum(TreeNode* node, const int targetSum, vector<int>& path, int& counter) {
    if (!node) return;
    long long sum {};
    path.push_back(node->val);
    auto it = path.rbegin();
    while (it != path.rend()) {
        sum += *it;
        if (sum == targetSum) {
            ++counter;
        }
        ++it;
    }
    findTargetSum(node->left, targetSum, path, counter);
    findTargetSum(node->right, targetSum, path, counter);
    path.pop_back();
}

int Solution::pathSumMain(TreeNode* root, int targetSum) {
    vector<int> path;
    int counter {};
    findTargetSum(root, targetSum, path, counter);
    return counter;
}

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