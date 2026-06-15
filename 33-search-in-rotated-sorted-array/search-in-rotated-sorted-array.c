void rotate(int* arr, int st_in, int end_in, int numsSize)
{
    int i = st_in;
    int j = end_in;
    int temp;
    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
int bin_search(int* nums, int target, int low, int high)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return bin_search(nums, target, low, mid - 1);
        else
            return bin_search(nums, target, mid + 1, high);
    }
    return -1;
}
int search(int* nums, int numsSize, int target) {
    int min = nums[0];
    int pos = 0;
    for(int i= 0; i< numsSize; i++)
    {
        if(nums[i] < min)
        {
            min = nums[i];
            pos = i;
        }
    }
    rotate( nums, 0, pos - 1, numsSize);
    rotate( nums, pos, numsSize - 1, numsSize);
    rotate( nums, 0, numsSize - 1, numsSize);
    
    int idx = bin_search(nums, target, 0, numsSize - 1);
    if(idx == -1) return -1;

    return (idx + pos) % numsSize;
}