int single(char s)
{
    int ans = 0;
    switch (s)
    {
        case 'I':
            ans = 1;
            break;
        case 'V':
            ans = 5;
            break;
        case 'X':
            ans = 10;
            break;
        case 'L':
            ans = 50;
            break;
        case 'C':
            ans = 100;
            break;
        case 'D':
            ans = 500;
            break;
        case 'M':
            ans = 1000;
            break;
    }
    return ans;
}
int romanToInt(char* s) {
    int ans = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        int first = single(s[i]);
        int second = (i+1 < n)? single(s[i+1]): 0;
        if(first < second)
            ans -= first;
        else
            ans += first;
    }
    return ans;
}