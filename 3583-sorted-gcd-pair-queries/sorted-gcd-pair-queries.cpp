class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = number of occurrences of x
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // divisible[g] = numbers divisible by g
        vector<long long> divisible(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g)
                divisible[g] += freq[multiple];
        }

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            // Total pairs divisible by g
            exact[g] = divisible[g] * (divisible[g] - 1) / 2;

            // Remove pairs whose gcd is a multiple of g
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exact[g] -= exact[multiple];
        }

        // prefix[i] = total pairs having gcd <= i
        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {

            // Find first gcd whose prefix > q
            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};