class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = n * n;
        long long sumEven = n * (n + 1);
        return gcd(sumOdd, sumEven);
    }
};