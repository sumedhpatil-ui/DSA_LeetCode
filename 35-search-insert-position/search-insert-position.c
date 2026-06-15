int bin_search(int* a, int lo, int hi, int tar)
{
    if(lo > hi)
        return lo;

    int mid = (lo + hi) / 2;
    int ret_val = mid;
    if(a[mid] == tar)
        ret_val = mid;
    else
    {
        if(mid > 0 && a[mid - 1] < tar && a[mid] > tar)
                ret_val = mid;
        else if(a[mid] > tar)
            ret_val = bin_search(a, lo, mid - 1, tar);
        else if(a[mid] < tar)
            ret_val = bin_search(a, mid + 1, hi, tar);
    }
    return ret_val;
}
int searchInsert(int* nums, int numsSize, int target) {
    int ret_val = bin_search(nums, 0, numsSize - 1, target);
    return ret_val;
}