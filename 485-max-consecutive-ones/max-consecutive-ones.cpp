class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                count++;
                max_ones = max(max_ones, count);
            }
            else 
                count = 0;
        }
        return max_ones;
    }
};