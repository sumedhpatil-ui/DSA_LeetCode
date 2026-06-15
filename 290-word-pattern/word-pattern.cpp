class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        string temp = "";
        
        // Split string into words
        for(char ch : s)
        {
            if(ch == ' ')
            {
                words.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }
        
        words.push_back(temp);

        // Sizes must match
        if(pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string w = words[i];

            // existing mapping mismatch
            if(mp1.count(c) && mp1[c] != w)
                return false;

            if(mp2.count(w) && mp2[w] != c)
                return false;

            mp1[c] = w;
            mp2[w] = c;
        }

        return true;
    }
};