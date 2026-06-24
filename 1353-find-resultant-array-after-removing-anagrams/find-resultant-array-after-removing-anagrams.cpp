class Solution {
public:
    bool isAnagram(string a, string b)
    {
        if(a.length() != b.length())
            return false;

        unordered_map<char, int> mpp;
        for(auto it : a)
        {
            mpp[it - 'a']++;
        }

        for(auto it : b)
        {
            if(mpp.find(it - 'a') == mpp.end() || mpp[it - 'a'] == 0)
            {
                return false;
            }
            mpp[it - 'a']--;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;        
        string prev = words[0];
        ans.push_back(prev);
        for(int i = 1; i < words.size(); i++)
        {
            if(!isAnagram(prev, words[i]))
            {
                ans.push_back(words[i]);
                prev = words[i];
            }
        }
        return ans;
    }
};