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
        vector<int> prefixGcd;
        int mx = nums[0];
        for(int &x : nums)
        {
            mx = max(mx, x);
            prefixGcd.push_back(gcd(mx, x));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int i = 0, j = n - 1;
        while(i < j)
            sum = sum +  gcd(prefixGcd[i++], prefixGcd[j--]);
        return sum;
    }
};