class Solution {
    // returns {zigzagLeft, zigzagRight}
    std::pair<int, int> dfs(TreeNode* node, int& maxZigZag) {
        if (!node) return {-1, -1}; // -1, bo dodamy +1 od razu

        auto [_, leftR] = dfs(node->left, maxZigZag);
        auto [rightL, _] = dfs(node->right, maxZigZag);

        int zigzagLeft  = leftR  + 1;
        int zigzagRight = rightL + 1;

        maxZigZag = std::max(std::max(maxZigZag, zigzagLeft), zigzagRight);
        return {zigzagLeft, zigzagRight};
    }

public:
    int longestZigZag(TreeNode* root) {
        int maxZigZag {};
        dfs(root, maxZigZag);
        return maxZigZag;
    }
};
