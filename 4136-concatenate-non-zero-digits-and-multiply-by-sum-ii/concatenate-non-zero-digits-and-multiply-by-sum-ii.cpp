class Solution {
public:
    long long mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n = s.size();
        int m = q.size();
        unordered_map<int, pair<int, int>> mpp; // index -> {num, sum}
        vector<int> cnt(n, 0);
        vector<int> pow10(n+1);
        long long num = 0;
        int sum = 0;
        int count = 0;
        pow10[0] = 1;
        for(int i = 1; i < n+1; i++)
            pow10[i] = (1ll * pow10[i-1]*10) % mod;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '0')
            {
                count++;
                num = (num * 10 + (s[i] - '0')) % mod;
                sum = (sum + (s[i] - '0')) % mod;
                mpp[i] = {num, sum};
            }
            else
                mpp[i] = {num, sum};
            cnt[i] = count;
        }
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++)
        {
            int l = q[i][0];
            int r = q[i][1];
            long long leftSum = 0;
            int leftNum = 0;
            int leftCnt = 0;
            if(l > 0)
            {
                leftNum = mpp[l-1].first;
                leftSum = mpp[l-1].second;
                leftCnt = cnt[l-1];
            }
            int nonZero = cnt[r] - leftCnt;
            long long left = (1LL * leftNum * pow10[nonZero]) % mod; 
            long long rightNum = mpp[r].first;
            int rightSum = mpp[r].second - leftSum;
            long long concat = (rightNum - left + mod) % mod;
            ans[i] = (1LL * concat * rightSum) % mod;
        }
        return ans;
    }
};