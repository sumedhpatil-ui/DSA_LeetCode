char * defangIPaddr(char * address){
    int n = strlen(address);
    char* s = (char*)malloc(1000);
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(address[i] == '.')
        {
            s[j++] = '[';
            s[j++] = '.';
            s[j++] = ']';
        }
        else
            s[j++] = address[i];
    }
    s[j] = '\0';
    return s;
}