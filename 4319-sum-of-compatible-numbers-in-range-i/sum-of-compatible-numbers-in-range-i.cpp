class Solution {
public:
    long long sumOfGoodIntegers(int n, int k) {
        long long ans = 0;

        long long L = max(1, n - k);
        long long R = 1LL * n + k;

        for(long long x = L; x <= R; x++) {
            if((x & n) == 0) {
                ans += x;
            }
        }

        return ans;
    }
};