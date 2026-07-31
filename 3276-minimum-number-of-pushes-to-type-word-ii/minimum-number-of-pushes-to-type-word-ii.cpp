class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto &it : word)
            freq[it - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            ans = ans +  freq[i] * (i/8 + 1);
        }
        return ans;
    }
};