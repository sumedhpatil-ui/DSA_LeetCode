class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum = 1;
        for(int i = 2; i < sqrt(num); i++)
        {
            if(num % i == 0)
                sum = sum + i + (num / i);
        }
        if(sqrt(num) * sqrt(num) == num)
            sum += sqrt(num);
        return sum == num;
    }
};