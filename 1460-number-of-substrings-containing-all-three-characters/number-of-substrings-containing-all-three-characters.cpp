class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        vector<int> freq(3, -1);
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a'] = i;
            if(freq[0] != -1 && freq[1] != -1 && freq[2] != -1)
            {
                int currCount = min(freq[0], min(freq[1], freq[2]));
                cnt = cnt + currCount + 1;
            }
        }
        return cnt;
    }
};