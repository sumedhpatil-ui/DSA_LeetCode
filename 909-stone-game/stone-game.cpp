class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<int> dp = piles;

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                dp[l] = max(
                    piles[l] - dp[l + 1],
                    piles[r] - dp[l]
                );
            }
        }

        return dp[0] > 0;
    }
};