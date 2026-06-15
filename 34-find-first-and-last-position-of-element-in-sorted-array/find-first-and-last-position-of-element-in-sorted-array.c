/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarysearch(int *arr, int lo, int hi, int tar)
{
    if(lo > hi)
        return -1;
    int mid = (hi + lo) / 2;
    if(arr[mid] == tar)
        return mid;
    else if(arr[mid] > tar)
        return binarysearch(arr, lo, mid - 1, tar);
    else
        return binarysearch(arr, mid + 1, hi, tar);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *arr = malloc(2 * sizeof(int));
    *returnSize = 2;
    int f_pos = -1, l_pos = -1;
    int t_pos = binarysearch(nums, 0, numsSize -1, target);
    printf("%d", t_pos);
    int i = t_pos, j = t_pos;
    if (t_pos == -1) 
    {
        arr[0] = arr[1] = -1;
        return arr;
    }
    while(i >= 0 && nums[i] == nums[t_pos])
    {
        f_pos = i;
        i--;
    }
    while(j < numsSize && nums[j] == nums[t_pos] )
    {
        l_pos = j;
        j++;
    }
    arr[0] = f_pos;
    arr[1] = l_pos;
    return arr;
}