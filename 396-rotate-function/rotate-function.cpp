class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long f = 0;
        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            f = f + i * nums[i];
        }

        long long maxSum = f;

        for(int i = 1; i < n; i++)
        {
            f = f + sum - (long long) n * nums[n - i];
            maxSum = max(maxSum, f);
        }
        return maxSum;
    }
};