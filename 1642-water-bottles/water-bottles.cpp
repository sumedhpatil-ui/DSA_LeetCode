class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int sum = numBottles;
        while(sum >= numExchange)
        {
            int unused = sum % numExchange;
            sum = sum / numExchange;
            ans = ans + sum;
            sum = sum + unused;
        }
        return ans;
    }
};