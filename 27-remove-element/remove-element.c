int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int j = numsSize - 1;
    int ans;
    while(i <= j)
    {
        if(nums[i] == val)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
            j--;
        }
        else
        {
            i++;
        }  
    }
    return i;
}