class Solution {
public:
    int sumSquares(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digits = n % 10;
            sum = sum + (digits*digits);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1)
        {
            if(st.find(n) != st.end())
                return false;
            st.insert(n);
            n = sumSquares(n);
        }  
        return true; 
    }
};