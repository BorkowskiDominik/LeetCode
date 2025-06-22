/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    Node* _construct(const vector<vector<int>>& grid, size_t start_x, size_t start_y, size_t size) {
        int value = grid[start_x][start_y];
        bool split_required = false;
        for (int i = start_x; i < start_x + size; ++i) {
            for (int j = start_y; j < start_y + size; ++j) {
                if (grid[i][j] != value) {
                    split_required = true;
                    break;
                }
            }
            if (split_required) break;
        }
        Node* head = new Node(value, !split_required);
        if (split_required) {
            auto child_size = size / 2;
            head->topLeft     = _construct(grid, start_x             , start_y             , child_size); 
            head->topRight    = _construct(grid, start_x             , start_y + child_size, child_size);
            head->bottomLeft  = _construct(grid, start_x + child_size, start_y             , child_size);
            head->bottomRight = _construct(grid, start_x + child_size, start_y + child_size, child_size);
        }
        return head;
    }

public:
    Node* construct(const vector<vector<int>>& grid) {
        return _construct(grid, 0, 0, grid.size());
    }
};