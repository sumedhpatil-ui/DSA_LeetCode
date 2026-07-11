class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        while(n != 0)
        {
            freq[n%10]++;
            n = n / 10;
        }
        int ans = INT_MAX;
        int index = 0;
        for(int i = 0; i < 10; i++)
        {
            if(freq[i] != 0 && freq[i] < ans)
            {
                ans = freq[i];
                index = i;
            }    
        }
        return index;
    }
};