class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0;
        int high = n;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(1LL * mid * (mid + 1) / 2 <= n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};