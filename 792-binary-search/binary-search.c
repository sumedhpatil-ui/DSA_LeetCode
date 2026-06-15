int bin_search(int nums[], int lo, int hi, int target)
{
    int ans;
    int mid = (hi + lo) / 2;
    if(lo > hi)
        ans = -1;
    else 
    {
        if(nums[mid] == target)
            ans = mid;
        else if(nums[mid] > target)
            ans = bin_search(nums, lo, mid-1, target);
        else if(nums[mid] < target)
            ans = bin_search(nums, mid+1, hi, target);
    }
    return ans;
}

int search(int* nums, int numsSize, int target) {
    int ans = bin_search(nums, 0, numsSize - 1, target);
    return ans;
}