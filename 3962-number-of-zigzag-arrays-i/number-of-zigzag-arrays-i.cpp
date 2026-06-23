class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m), down(m);
        vector<long long> pref(m);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> nup(m), ndown(m);

            pref[0] = down[0];
            for (int i = 1; i < m; i++)
                pref[i] = (pref[i - 1] + down[i]) % MOD;

            for (int i = 0; i < m; i++)
                nup[i] = (i ? pref[i - 1] : 0);

            pref[0] = up[0];
            for (int i = 1; i < m; i++)
                pref[i] = (pref[i - 1] + up[i]) % MOD;

            long long total = pref[m - 1];

            for (int i = 0; i < m; i++)
                ndown[i] = (total - pref[i] + MOD) % MOD;

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = (ans + up[i] + down[i]) % MOD;

        return ans;
    }
};