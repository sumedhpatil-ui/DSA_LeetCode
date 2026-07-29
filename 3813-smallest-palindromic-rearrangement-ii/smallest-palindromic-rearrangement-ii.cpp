class Solution {
public:
    int per; 

    long long nCr(int n, int r, long long limit)
    {
        if(r > n)
            return 0;

        r = min(r, n - r);

        long long ans = 1;

        for(int i = 1; i <= r; i++)
        {
            __int128 cur = (__int128)ans * (n - r + i);
            cur /= i;

            if(cur > limit)
                return limit + 1;

            ans = (long long)cur;
        }

        return ans;
    }

    long long countPerm(vector<int>& freq, int total)
    {
        long long ans = 1;
        int rem = total;

        for(int f : freq)
        {
            if(f == 0)
                continue;

            long long ways = nCr(rem, f, per);

            // If ans * ways would exceed per, cap it.
            if(ways != 0 && ans > per / ways)
                return per + 1;

            ans *= ways;

            if(ans > per)
                return per + 1;

            rem -= f;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        per = k;
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n / 2; i++)
            freq[s[i] - 'a']++;
        
        int id = 0;
        int total = countPerm(freq, n / 2);
        if(total < k)
            return "";
        while(id < n /2)
        {
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] == 0)
                    continue;
                freq[i]--;
                int count = countPerm(freq, n / 2 - id - 1);

                if(count >= k)
                {
                    s[id] = (char)('a' + i);
                    s[n - 1 - id] = s[id];
                    id++;
                    break;
                }
                k -= count;
                freq[i]++;
            }
        }
        return s;
    }
};