class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int allXor = 0;
        for(int i = 0; i < n; i++)
        {
            allXor = allXor ^ nums[i];
        }
        int bit = 0;
        int index = 0;
        while(allXor != 0)
        {
            bit = (allXor & 1);
            if(bit == 1)
                break;
            index++;    
            allXor >>= 1;
        }
        int group1 = 0;
        int group2 = 0;

        int setBit = 1 << index;
        for(int i = 0; i < n; i++)
        {
            if((setBit & nums[i]) == 0)
            {
                group1 = group1 ^ nums[i];
            }
            else
                group2 = group2 ^ nums[i];
        }
        return {group1, group2};
    }
};