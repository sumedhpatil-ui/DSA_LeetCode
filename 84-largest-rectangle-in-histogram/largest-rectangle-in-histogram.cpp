class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        stack<int> st2;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();
            if(st2.empty())
                right[i] = n;
            else
                right[i] = st2.top();
            st2.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            ans = max(ans, width * heights[i]);
        }
        return ans;
    }
};