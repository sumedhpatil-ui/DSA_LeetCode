int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max_sum = -1000000;
    for(int i = 0; i < numsSize; i++)
    {   
        if(sum < 0)
            sum = nums[i];
        else
            sum = sum + nums[i]; 
        if(sum > max_sum)
            max_sum = sum;
    }
    return max_sum;
}