/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        std::vector<Node*> val_to_new_node(101, nullptr);
        std::vector<bool> visited(101, false);
        std::vector<Node*> que;
        que.push_back(node);
        while(!que.empty()) {
            auto old = que.back(); que.pop_back();
            if (!val_to_new_node[old->val]) {
                val_to_new_node[old->val] = new Node(old->val);
            }
            if (!visited[old->val]){
                visited[old->val] = true;
                std::vector<Node*> neighbors; 
                for (const auto& n : old->neighbors) {
                    if (!val_to_new_node[n->val]) {
                        val_to_new_node[n->val] = new Node(n->val);
                    }
                    neighbors.push_back(val_to_new_node[n->val]);
                    if (!visited[n->val])
                        que.push_back(n);
                }
                val_to_new_node[old->val]->neighbors = std::move(neighbors);
            }
        }
        return val_to_new_node[node->val];
    }
};