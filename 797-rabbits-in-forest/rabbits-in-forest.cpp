class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int hashSize = 0;
        for(int x : answers)
            hashSize = max(hashSize, x);
        vector<int> hash(hashSize + 1, 0);
        for(auto it : answers)
        {
            hash[it]++;
        }
        int ans = 0;
        for(int i = 0; i <= hashSize; i++)
        {
            int groups = 0;
            if(hash[i] == 0)
                continue;
            else
            {
                groups = (hash[i] + i) / (i + 1);
            }
            ans += groups * (i + 1); 
        }
        return ans;
    }
};