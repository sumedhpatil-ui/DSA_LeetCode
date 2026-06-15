class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(int x : nums)
        {
            if(x == third || x == second || x == first)
                continue;
            if(x > first)
            {
                third = second;
                second = first;
                first = x;
            }
            else if(x > second)
            {
                third = second;
                second = x;
            }
            else if(x > third)
            {
                third = x;
            }
        }
        return third != LLONG_MIN ? third : first;
    }
};