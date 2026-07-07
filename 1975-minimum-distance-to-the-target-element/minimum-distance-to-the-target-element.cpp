class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size();
        int i = start;
        while(i >= 0)
        {
            if(nums[i] == target)
            {
                ans = min(ans, start - i);
                break;
            }
            i--;
        }
        i = start + 1;
        while(i < n)
        {
            if(nums[i] == target)
            {
                ans = min(ans, i - start);
                break;
            }
            i++;
        }
        return ans;
    }
};