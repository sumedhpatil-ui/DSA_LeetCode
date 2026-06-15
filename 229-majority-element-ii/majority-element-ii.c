/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int* ans = (int*)malloc(2 * sizeof(int));
    int f_el, s_el;
    int f_cnt = 0, s_cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(f_cnt == 0 && nums[i] != s_el)
        {
            f_cnt = 1;
            f_el = nums[i];
        }
        else if(s_cnt == 0 && nums[i] != f_el)
        {
            s_cnt = 1;
            s_el = nums[i];
        }
        else if(nums[i] == f_el) f_cnt++;
        else if(nums[i] == s_el) s_cnt++;
        else
        {
            f_cnt--;
            s_cnt--;
        }
    }
    f_cnt = 0;
    s_cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == f_el)
        {
            f_cnt++;
        }
        if(nums[i] == s_el)
        {
            s_cnt++;
        }
    }
    int mini = (int)(numsSize / 3) + 1;
    if(f_cnt >= mini) 
        ans[(*returnSize)++] = f_el;
    if(s_cnt >= mini)
        ans[(*returnSize)++] = s_el;
    return ans;
}