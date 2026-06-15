class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int rw = 0;
        bool down = true;

        for(int i = 0; i < s.size(); i++)
        {
            rows[rw] += s[i];

            if(rw == numRows - 1)
                down = false;

            else if(rw == 0)
                down = true;

            if(down)
                rw++;
            else
                rw--;
        }

        string ans = "";

        for(auto it : rows)
            ans += it;

        return ans;
    }
};