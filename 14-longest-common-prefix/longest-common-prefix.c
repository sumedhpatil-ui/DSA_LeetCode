char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";

    int idx = 0;

    while (1)
    {
        char ch = strs[0][idx];
        if (ch == '\0')
            break;

        for (int i = 1; i < strsSize; i++)
        {
            if (strs[i][idx] != ch)
                goto end;
        }
        idx++;
    }

end:
    char* ans = (char*)malloc((idx + 1) * sizeof(char));
    for (int i = 0; i < idx; i++)
        ans[i] = strs[0][i];

    ans[idx] = '\0';
    return ans;
}
