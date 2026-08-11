class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];

        // Calculate the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                prefixSum += nums[i];
            else
                break;
        }

        // Store all numbers for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Find the smallest integer >= prefixSum not in the array
        while (st.count(prefixSum))
            prefixSum++;

        return prefixSum;
    }
};