class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, int numEl, int target, vector<int> temp, int k)
    {
        if(target == 0)
        {
            if(numEl == k)
                ans.push_back(temp);
            return;
        }
        if(index > 9 || numEl == k || target < 0)
            return;
        temp.push_back(index);
        helper(index+1, numEl + 1, target - index, temp, k);
        temp.pop_back();
        helper(index+1, numEl, target, temp, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(1, 0, n, temp, k);
        return ans;
    }
};