class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int> temp, vector<int>& nums, int n)
    {
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(index+1, temp, nums, n);
        temp.pop_back();
        helper(index+1, temp, nums,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(0, temp, nums, nums.size());
        return ans;
    }
};