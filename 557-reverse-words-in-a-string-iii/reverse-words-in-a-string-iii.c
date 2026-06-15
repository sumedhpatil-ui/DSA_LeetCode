void reverse(char* s, int st, int end)
{
    while(st < end)
    {
        char a = s[st];
        s[st] = s[end];
        s[end] = a;
        st++;
        end--;
    }
}
char* reverseWords(char* s) {
    int i = 0;
    int n = strlen(s);
    int start = 0;
    while(i <= n)
    {
        if(s[i] == ' ' || s[i] == '\0')
        {
            reverse(s, start, i-1);
            start = i + 1;
        }
        i++;
    }
    return s;
}