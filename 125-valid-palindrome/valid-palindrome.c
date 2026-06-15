#include <string.h>
#include <ctype.h>
bool check(char* s, int a, int b) 
{
    if( a >= b)
        return true;
    else
    {
        if(isalnum((unsigned char)s[a]))
        {
            if(isalnum((unsigned char)s[b]))
            {
                if (tolower((unsigned char)s[a]) == tolower((unsigned char)s[b]))
                    return  check(s, a+1, b-1);
                else
                    return false;
            }
            else 
                return check(s, a, b-1);
        }
        else
            return check(s, a+1, b);
    }
}
bool isPalindrome(char* s)
{
    bool x = check(s, 0, strlen(s)-1);
    return x;
}