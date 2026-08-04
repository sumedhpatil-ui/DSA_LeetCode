class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }

        vector<int> ans;
        vector<int> temp(mx - mn + 1, 0);
        for(int i = 0; i < n; i++)
        {
            temp[nums[i] - mn] = 1;
        }

        for(int i = 0; i < mx - mn + 1; i++)
        {
            if(temp[i] == 0)
                ans.push_back(mn + i);
        }
        return ans;
    }
};