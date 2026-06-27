class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, int target, vector<int>& temp, vector<int>& candidates, int n)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(index == n)
        {
            return;
        }
        if(candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            helper(index, target - candidates[index], temp, candidates, n);
            temp.pop_back();
        }
        helper(index + 1, target, temp, candidates, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        helper(0, target, temp, candidates, n);
        return ans;
    }
};