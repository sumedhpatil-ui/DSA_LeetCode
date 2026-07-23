class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                left[i] = i + 1;
            else   
                left[i] = i - st.top();
            st.push(i);
        }
        stack<int> rt;
        for(int i = n-1; i >= 0; i--)
        {
            while(!rt.empty() && arr[rt.top()] > arr[i])
                rt.pop();
            if(rt.empty())
                right[i] = n - i;
            else
                right[i] = rt.top() - i;
            rt.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            long long contri = (1LL * left[i] * right[i] * arr[i]);
            ans += contri;
            ans %= mod;
        }
        return ans;
    }
};