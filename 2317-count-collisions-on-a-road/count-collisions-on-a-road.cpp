class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int ans = n;
        int i = 0;
        while(i < n && dir[i] == 'L')
            i++;
        ans = ans - i;
        int j = n - 1;
        while(j >= 0 && dir[j] == 'R')
            j--;
        ans = ans - (n - 1 - j);
        for(int x = i; x <= j; x++)
        {
            if(dir[x] == 'S')
                ans--;
        }
        return ans;
    }
};