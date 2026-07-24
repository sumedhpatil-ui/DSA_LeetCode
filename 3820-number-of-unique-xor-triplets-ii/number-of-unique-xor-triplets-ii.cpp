class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        unordered_set<int> ans;

        int n = nums.size();

        for (int x : nums)
            ans.insert(x);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p : pairXor) {
            for (int x : nums) {
                ans.insert(p ^ x);
            }
        }

        return ans.size();
    }
};