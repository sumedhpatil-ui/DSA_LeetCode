class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;

        for(auto it : columnTitle)
        {
            ans = ans * 26;
            ans = ans + (it - 'A' + 1);
        }
        return ans;
    }
};