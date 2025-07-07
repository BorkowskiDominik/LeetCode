class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        triangle[0].push_back(1);
        for (int i = 0; i < numRows-1; ++i) {
            triangle[i+1].resize(triangle[i].size()+1);
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i+1][j] += triangle[i][j];
                triangle[i+1][j+1] += triangle[i][j];
            }
        }
        return triangle;
    }
};