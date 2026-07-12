class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++)
        {   
            mpp[s[i] - 'a']++;
        }
        int ans = 0;
        int oddMax = 0;
        for(auto it : mpp)
        {
            if(it.second % 2 == 0)
                ans += it.second;
            else
            {
                ans += it.second - 1;
                oddMax = 1;
            }
        }
        if(oddMax)
            ans++;
        return ans;
    }
};