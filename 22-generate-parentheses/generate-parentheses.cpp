class Solution {
public:
    bool isValid(string& s)
    {
        stack<char> st;
        for(char c : s)
        {
            if(c == '(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    void generate(int n, string curr, vector<string>& ans)
    {
        int len = curr.size();
        if(len == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        generate(n, curr + '(', ans);
        generate(n, curr + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> temp;
        generate(n, "", temp);

        vector<string> ans;
        for(auto it : temp)
        {
            if(isValid(it))
            {
                ans.push_back(it);
            }
        } 
        return ans;   
    }
};