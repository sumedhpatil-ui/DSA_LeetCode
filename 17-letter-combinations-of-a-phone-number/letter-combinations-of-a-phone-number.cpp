class Solution {
public:
    vector<string> ans;
    void helper(int index, string temp, string &digits, unordered_map<char, vector<char>> &mp)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int n = mp[digits[index]].size();
        for(int i = 0; i < n; i++)
        {
            auto it = mp[digits[index]];
            helper(index+1, temp + it[i], digits, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        helper(0, {}, digits, mp); // {string index, index, temp string}
        return ans;
    }
};