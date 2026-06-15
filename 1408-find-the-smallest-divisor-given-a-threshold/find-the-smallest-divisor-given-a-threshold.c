int sumbyD(int arr[], int n, int d)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += (arr[i] + d -1) / d;
    }
    return sum;
}
int smallestDivisor(int* nums, int numsSize, int threshold) {
    int low = 1;
    int high = nums[0];
    for(int i = 0; i < numsSize; i++)
        if(nums[i] > high)
            high = nums[i];
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int sum = sumbyD(nums, numsSize, mid);
        if(sum <= threshold)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return low;
}