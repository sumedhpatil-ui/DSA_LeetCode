class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void helper(int start, int sum, int target, vector<int>& arr) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i-1]) continue; // skip duplicates at this level
            if (sum + arr[i] > target) break; // sorted, so no point going further
            temp.push_back(arr[i]);
            helper(i+1, sum + arr[i], target, arr);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(0, 0, target, candidates);
        return ans;
    }
};