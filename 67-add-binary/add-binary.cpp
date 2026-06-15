class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        string c = "";

        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if(i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }

            if(j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            c += (sum % 2) + '0';

            carry = sum / 2;
        }

        reverse(c.begin(), c.end());

        return c;
    }
};