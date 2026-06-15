char* toLowerCase(char* s) {
    int i;
    int n = strlen(s);
    for(i = 0; i < n; i++)
    {
        if(s[i] <= 90 && s[i] >= 65)
            s[i] = s[i] + 32;
    }
    return s;
}