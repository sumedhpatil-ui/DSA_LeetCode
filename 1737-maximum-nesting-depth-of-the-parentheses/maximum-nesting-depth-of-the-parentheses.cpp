class Solution {
public:
    int maxDepth(string s) {
    int max_depth = 0;
    int balance = 0;
    for(auto c : s)
    {
        if(c == '(')    balance++;
        if(c == ')')    balance--;
        max_depth = max(max_depth, balance);
    }
    return max_depth;
    }
};