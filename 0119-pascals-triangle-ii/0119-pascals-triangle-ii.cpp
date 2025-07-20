
class Solution {
    // can be done with formula directy
    // int binomial(int a, int b) {
    //     return 0;
    // }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.reserve(rowIndex + 1);
        row.push_back(1);
        for (int i = 0; i  < rowIndex; ++i) {
            row.push_back(1);
            for (int j = row.size()-2; j > 0; --j) {
                row[j] = row[j] + row[j-1];
            }
        }
        return row;
    }
};