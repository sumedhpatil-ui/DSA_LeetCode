int num_sub(int* arr, int n, int sum)
{
    int cnt_sub = 1;
    int sum_sub = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum_sub + arr[i] <= sum)
            sum_sub += arr[i];
        else
        {
            sum_sub = arr[i];
            cnt_sub++;
        }
    }
    return cnt_sub;
}
int splitArray(int* nums, int numsSize, int k) {
    int low = nums[0];
    int high = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        high += nums[i];
        if(nums[i] > low)
            low = nums[i];
    }
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int num_arr = num_sub(nums, numsSize, mid);
        if(num_arr <= k)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return low;
}