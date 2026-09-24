class Solution {
public:
    int sumDig(int num)
    {
        int sum = 0;
        while(num != 0)
        {
            sum = sum + (num % 10);
            num = num / 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(sumDig(nums[i]) == i)
            {
                return i;
            }
        }
        return -1;
    }
};