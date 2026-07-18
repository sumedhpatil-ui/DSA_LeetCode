class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int small = nums[0];
        int large = nums[0];
        for(int i = 0; i < n; i++) 
        {
            small = min(small, nums[i]);
            large = max(large, nums[i]);
        }
        return gcd(large, small);
    }
};