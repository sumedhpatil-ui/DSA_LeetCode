class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long ans = 0;
        int one = 0;
        unordered_map<long long, int> mp; // {num, freq}
        for(auto &it : nums)
        {
            if(it == 1)
            {
                one++;
            }
            else
                mp[it]++;
        }

        if(one % 2 == 0)
            ans = one - 1;
        else 
            ans = one;

            
        for (auto &[x, f] : mp) {
            long long val = x;
            long long cnt = 0;

            while (mp.count(val) && mp[val] >= 2) {
                cnt += 2;
                if (val > 1e9) break; // avoid overflow if desired
                val *= val;
            }

            if (mp.count(val) && mp[val] == 1)
                cnt++;
            else
                cnt--;

            ans = max(ans, cnt);
        }
        return ans;
    }
};