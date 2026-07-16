class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = nums[0];
        for(int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int i = 0, j = n - 1;
        while(i < j)
        {
            sum = sum +  gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};