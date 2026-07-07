class Solution {
public:
    long long sumAndMultiply(int n) {
        stack<int> st;
        long long sum = 0;
        while(n != 0)
        {
            int dig = n % 10;
            if(dig != 0){
                sum += dig;
                st.push(dig);
            }
            n = n / 10;
        }

        long long ans = 0;
        while(!st.empty())
        {
            int dig = st.top();
            st.pop();
            ans = ans * 10 + dig;
        }
        return ans * sum;
    }
};