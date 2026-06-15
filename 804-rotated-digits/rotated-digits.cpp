class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        int j = 0;
        for(int i=1; i <= n; i++)
        {
            int ic = i;
            int curr = 0;

            while(ic)
            {
                j = ic % 10;
                if(j ==3 || j == 7 || j == 4)
                {
                    curr = 0;
                    break;
                }
                if(j == 2 || j == 5 || j == 6 || j == 9)
                {
                    curr = 1;
                }
                ic /= 10;
            }
            ans += curr;
        }
        return ans;
    }
};