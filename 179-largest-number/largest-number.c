#include <string.h>
#include <stdlib.h>

char* largestNumber(int* nums, int numsSize) {
    char *str_nums[numsSize];
    char temp[25];
    int total_len = 0;

    for(int i = 0; i < numsSize; i++) {
        str_nums[i] = malloc(12);
        sprintf(str_nums[i], "%d", nums[i]);
        total_len += strlen(str_nums[i]);
    }

    char ba[25], ab[25];

    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {

            strcpy(ba, str_nums[i]);
            strcat(ba, str_nums[j]);

            strcpy(ab, str_nums[j]);
            strcat(ab, str_nums[i]);

            if(strcmp(ab, ba) > 0) {
                strcpy(temp, str_nums[i]);
                strcpy(str_nums[i], str_nums[j]);
                strcpy(str_nums[j], temp);
            }
        }
    }

    char *result = malloc(total_len + 1);
    result[0] = '\0';

    for(int i = 0; i < numsSize; i++)
        strcat(result, str_nums[i]);

    if (result[0] == '0')
        result[1] = '\0';

    return result;
}