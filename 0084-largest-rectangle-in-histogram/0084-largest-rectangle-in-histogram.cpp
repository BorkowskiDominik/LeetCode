class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st; // can be stack but using vector for performance
        st.reserve(heights.size());
        heights.push_back(0);
        int maxArea = heights.front();

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.back()]) {
                int h = heights[st.back()]; st.pop_back();
                int w = st.empty() ? i : i - st.back() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push_back(i);
        }
        return maxArea;
    }
};