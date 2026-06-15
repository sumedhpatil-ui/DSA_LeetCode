class Solution {
public:
    bool isPrimes(int n )
    {
        return (n == 2 || n ==3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19);
    }
    int countPrimeSetBits(int left, int right) {

        int result = 0;

        for(int i = left; i <= right; i++){
            int bits = __builtin_popcount(i);
            if(isPrimes(bits)){
                result++;
            }
        }
        return result;
    }
};