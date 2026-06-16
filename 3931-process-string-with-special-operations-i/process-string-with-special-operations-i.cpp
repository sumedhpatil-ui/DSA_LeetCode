class Solution {
public:
    string processStr(string s) {
        string ans;
        for(auto &it : s)
        {
            if(ans.size() != 0 && it == '*')
            {
                ans.pop_back();
            }
            else if(it == '#')
            {
                ans += ans;
            }
            else if(it == '%')
            {
                reverse(ans.begin(), ans.end());
            }
            else if(it >= 97 && it <= 122)
            {
                ans = ans + it;
            }
        }
        return ans;
    }
};