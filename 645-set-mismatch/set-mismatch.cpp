class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long S = n * (n + 1) / 2;
        long long S2 = n * (n + 1) * (2 * n + 1) / 6;

        long long A = 0, A2 = 0;
        for(int x : nums) {
            A += x;
            A2 += (long long)x * x;
        }

        long long diff = A - S;              // D - M
        long long sum = (A2 - S2) / diff;    // D + M

        int D = (diff + sum) / 2;
        int M = D - diff;

        return {D, M};
    }
};
