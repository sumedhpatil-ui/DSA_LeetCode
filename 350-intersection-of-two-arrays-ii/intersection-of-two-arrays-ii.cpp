class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       int arrSize = 0;
       for(auto it : nums1)
            arrSize = max(arrSize, it);
       for(auto it : nums2)
            arrSize = max(arrSize, it);

        vector<int> freq(arrSize + 1, 0);
        for(auto it : nums1)
        {
            freq[it]++;
        }

        vector<int> ans;
        for(auto it : nums2)
        {
            if(freq[it] > 0)
            {
                ans.push_back(it);
                freq[it]--;
            }
        }
        return ans;
    }
};