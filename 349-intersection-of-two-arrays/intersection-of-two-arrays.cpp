class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int numMax = 0;
        for(auto it : nums1)
            numMax = max(numMax, it);

        for(auto it : nums2)
            numMax = max(numMax, it);
        vector<int> freq(numMax + 1, 0);
        for(auto it : nums1)
        {
            freq[it] = 1;
        }
        for(auto it : nums2)
        {
            if(freq[it] == 1)
                freq[it] = 2;
        }

        vector<int> ans;
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i] == 2)
                ans.push_back(i);
        }
        return ans;
    }
};