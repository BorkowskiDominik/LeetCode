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
struct Range {
    size_t x;
    size_t y;
    size_t size;
};

class Solution {
    template<typename T>
    using TVV = std::vector<std::vector<T>>;

    Node* _construct(const TVV<int>& grid, const TVV<size_t>& prefix_sum, Range r) {
        bool split_required = !is_homogeneous(grid, prefix_sum, r);
        Node* head = new Node(grid[r.x][r.y], !split_required);
        if (split_required) {
            auto q_size = r.size / 2;
            head->topLeft     = _construct(grid, prefix_sum, {r.x         , r.y         , q_size}); 
            head->topRight    = _construct(grid, prefix_sum, {r.x         , r.y + q_size, q_size});
            head->bottomLeft  = _construct(grid, prefix_sum, {r.x + q_size, r.y         , q_size});
            head->bottomRight = _construct(grid, prefix_sum, {r.x + q_size, r.y + q_size, q_size});
        }
        return head;
    }

    inline bool is_homogeneous(const TVV<int>& grid, const TVV<size_t>& prefix_sum, const Range& r) {
        size_t region_sum =   prefix_sum[r.x+r.size][r.y+r.size]
                            + prefix_sum[r.x][r.y]
                            - prefix_sum[r.x+r.size][r.y]
                            - prefix_sum[r.x][r.y+r.size];

        return region_sum == 0 || region_sum == r.size*r.size;
    }

    TVV<size_t> _generate_prefix_sum (const TVV<int>& grid) {
        auto grid_size = grid.size();
        TVV<size_t> p_sum(grid_size+1, vector<size_t>(grid_size+1, 0));
        
        for (size_t i = 0; i < grid_size; ++i) {
            for (size_t j = 0; j < grid_size; ++j) {
                p_sum[i+1][j+1] =  grid[i][j]
                                + p_sum[i][j+1]
                                + p_sum[i+1][j]
                                - p_sum[i][j];
            }
        }
        return p_sum;
    }

public:
    Node* construct(const TVV<int>& grid) {
        auto prefix_sum = _generate_prefix_sum(grid);
        return _construct(grid, prefix_sum, {0, 0, grid.size()});
    }
};