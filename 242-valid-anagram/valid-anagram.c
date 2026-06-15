bool isAnagram(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int wc[26] = {0};;
    if(len1 == 0 || len1 != len2)
        return false; 
    else
    {
        for(int i = 0; i < len1; i++)
        {
            wc[s[i] - 'a']++;
        }
        printf("\n");
        for(int j = 0; j < len2; j++)
        { 
            wc[t[j] - 'a']--;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(wc[i] != 0)
            return false;
    } 
    return true;
}