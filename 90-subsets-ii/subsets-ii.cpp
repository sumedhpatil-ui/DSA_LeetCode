class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int>& arr, vector<int> temp, int n)
    {
        ans.push_back(temp);
        for(int i = index; i < n; i++)
        {
            if(i > index && arr[i] == arr[i-1])
                continue;
            temp.push_back(arr[i]);
            helper(i+1, arr, temp, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(0, nums, temp, nums.size());
        return ans;
    }
};