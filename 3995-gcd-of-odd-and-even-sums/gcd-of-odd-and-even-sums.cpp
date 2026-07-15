class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = n * n;
        long long sumEven = n * (n + 1);
        long long ans = n;
        for(int i = n; i < n * n; i++)
        {
            if(sumOdd % i == 0 && sumEven % i == 0)
                ans = i;
        }
        return ans;
    }
};