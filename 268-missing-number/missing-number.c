int missingNumber(int* nums, int numsSize) {
    int temp = 0;
    for(int i = 0; i < numsSize; i++)
    {
        temp ^= i;
        temp ^= nums[i];
    }
    temp ^= numsSize;
    return temp;
}