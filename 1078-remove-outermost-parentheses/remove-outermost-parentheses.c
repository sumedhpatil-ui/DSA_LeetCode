char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char* ans = (char*)malloc((n+1) * sizeof(char));
    int idx = 0;
    int balance = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            if(balance > 0)
                ans[idx++] = '(';
            balance++;
        }
        else
        {
            balance--;
            if(balance > 0)
                ans[idx++] = ')';
        }
    }
    ans[idx] = '\0';
    return ans;
}