class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int idx = 1;
        while(n > 8)
        {
            ans += (idx * 8);
            n -= 8;
            idx++;
        }
        ans += n * idx;
        return ans;
    }
};