int maxProduct(int* nums, int numsSize) {
    int maxP = nums[0], minP = nums[0], ans = nums[0];

    for(int i = 1; i < numsSize; i++) {
        int a = maxP * nums[i];
        int b = minP * nums[i];

        maxP = nums[i] > a ? nums[i] : a;
        maxP = maxP > b ? maxP : b;

        minP = nums[i] < a ? nums[i] : a;
        minP = minP < b ? minP : b;

        ans = ans > maxP ? ans : maxP;
    }
    return ans;
}
