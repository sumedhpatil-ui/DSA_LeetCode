class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int ansLen = n + m + 1;
        string ans(ansLen, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < n; i++)
        {
            int carry = 0;
            for(int j = 0; j < m; j++)
            {
                int product = ans[i + j] - '0';
                product += (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = product / 10; 
                product = product % 10;
                ans[i+j] = product + '0';
            }
            ans[i+m] = carry + '0';
        }
        reverse(ans.begin(), ans.end());
        string finalAns = "";
        int i = 0;
        while(i < ansLen && ans[i] == '0')
            i++;
        if(i == ansLen)
            return "0";
        while(i < ansLen)
        {
            finalAns += ans[i];
            i++;
        }
        return finalAns;
    }
};