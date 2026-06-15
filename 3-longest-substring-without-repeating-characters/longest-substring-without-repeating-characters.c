bool check_char(char* s, int lo, int hi, char a)
{
    for(int i = lo; i < hi; i++)
    {
        if(s[i] == a)
            return false;
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int st = 0;
    int max_length = 1;
    int temp_length = 1;

    for(int i = 1; i < n; i++)
    {
        if(check_char(s, st, i, s[i]))
        {
            temp_length++;
        }
        else
        {
            if(temp_length > max_length)
                max_length = temp_length;
            while(s[st] != s[i])
                st++;

            st++;
            temp_length = i - st + 1;
        }
    }

    if(temp_length > max_length)
        max_length = temp_length;

    return max_length;
}
