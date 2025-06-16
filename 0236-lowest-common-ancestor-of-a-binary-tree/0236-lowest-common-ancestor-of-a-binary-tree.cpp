/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    std::vector<std::vector<TreeNode*>> paths;
    bool p_found;
    bool q_found;
public:
    bool find(std::vector<TreeNode*>& path, TreeNode* p, TreeNode* q) {
        auto tail = path.back();
        if (!p_found && p == tail) {
            p_found = true;
            paths.push_back(path);
        }
        if (!q_found && q == tail) {
            q_found = true;
            paths.push_back(path);
        }
        if (p_found && q_found) return true;
        if (auto left = tail->left; left){
            path.push_back(left);
            if (find(path, p, q)) return true;
            path.pop_back();
        }
        if (auto right = tail->right; right) {
            path.push_back(right);
            if (find(path, p, q)) return true;
            path.pop_back();
        }
        return false;
    }

    void init() {
        paths.clear();
        p_found = false;
        q_found = false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        init();
        std::vector<TreeNode*> path {root};
        find(path, p , q);
        if (paths.size() < 2) return nullptr;
        int idx = 0;
        for(int i = 0; i < std::min(paths[0].size(), paths[1].size()); ++i) {
            if (paths[0][i] == paths[1][i])
                idx = i;
            else
                break;
        }
        return paths[0][idx];
    }
};