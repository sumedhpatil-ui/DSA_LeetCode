/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int *a = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    if(!a)
        return NULL;
    int j = 1, k = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] % 2 == 1)
        {
            a[j] = nums[i];
            j = j + 2;
        }
        else
        {
            a[k] = nums[i];
            k = k + 2;
        }
    }   
    return a; 
}