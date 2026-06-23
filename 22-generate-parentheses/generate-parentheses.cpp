class Solution {
public:
    void generate(int open, int close, string curr, vector<string>& ans)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(curr);
            return;
        }
        if(open > 0)
            generate(open - 1, close, curr + "(", ans);
        if(close > open)
            generate(open, close - 1, curr + ")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, n, "", ans);
        return ans;
    }
};