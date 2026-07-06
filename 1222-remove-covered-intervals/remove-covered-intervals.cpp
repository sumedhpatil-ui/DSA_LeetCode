class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int n = intervals.size();
        int cnt = 1;
        int maxEnd = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][1] > maxEnd)
            {
                cnt++;
                maxEnd = intervals[i][1];
            }
        }
        return cnt;
    }
};