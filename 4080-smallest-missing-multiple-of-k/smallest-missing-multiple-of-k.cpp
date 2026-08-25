class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int mul = k; ; mul += k) {
            if (st.find(mul) == st.end()) {
                return mul;
            }
        }
    }
};