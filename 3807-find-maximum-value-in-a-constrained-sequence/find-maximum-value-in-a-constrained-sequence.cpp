class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> heights(n, 1e9);
        heights[0] = 0; 
        for(auto it : restrictions)
        {
            heights[it[0]] = min(heights[it[0]], it[1]);
        }
        
        for(int i = 0; i < n-1 ; i++)
        {
            heights[i + 1] = min(heights[i+1], heights[i] + diff[i]);
        }
        int ans = 0;
        for(int j = n-2; j >= 0; j--)
        {
            heights[j] = min(heights[j], heights[j+1] + diff[j]);
            ans = max(ans, heights[j]);
        }

        return max(ans, heights[n-1]);
    }
};