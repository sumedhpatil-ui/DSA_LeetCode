char* reverseWords(char* s) {
    int n = strlen(s);
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    int i = n - 1;
    while(i >= 0)
    {
        while(i >= 0 && s[i] == ' ')
            i--;

        if(i < 0) break;

        int j = i;
        while(j >= 0 && s[j] != ' ')
            j--;
        for(int k = j + 1; k <= i; k++)
            ans[idx++] = s[k];

        ans[idx++] = ' ';
        i = j - 1;
    }

    if(idx > 0) idx--;   
    ans[idx] = '\0';

    return ans;
}
