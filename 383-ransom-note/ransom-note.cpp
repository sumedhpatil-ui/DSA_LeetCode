class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++)
        {
            char ch = magazine[i];
            freq[ch - 'a']++;
        }
        
        bool ans = true;
        for(auto it : ransomNote)
        {
            freq[it - 'a']--;
                
            if(freq[it - 'a'] < 0)
                return false;
        }
        return ans;
    }
};