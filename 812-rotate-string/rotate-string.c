#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    int n = strlen(s);
    if (n != strlen(goal))
        return false;

    if (n == 0)
        return true;

    char temp[2001];
    strcpy(temp, s);
    strcat(temp, s);

    return strstr(temp, goal) != NULL;
}
