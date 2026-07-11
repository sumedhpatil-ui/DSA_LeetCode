class Solution {
public:
    bool check(int n)
    {
        if(n < 10)
            return true;
        int dup = n;
        while(n != 0)
        {
            int digit = n % 10;
            if(digit == 0 || dup % digit != 0)
                return false;
            n = n / 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++)
        {
            if(check(i) == true)
                ans.push_back(i);
        }
        return ans;
    }
};