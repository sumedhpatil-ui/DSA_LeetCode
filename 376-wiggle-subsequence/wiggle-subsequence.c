int wiggleMaxLength(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1)
        return numsSize;
    int up_count = 1, down_count = 1;
    for(int i = 0; i < numsSize -1; i++)
    {
        if(nums[i] < nums[i+1])
            up_count = down_count + 1;
        else if(nums[i] > nums[i+1])
            down_count = up_count + 1;
    }
    return (up_count > down_count)? up_count : down_count;
}