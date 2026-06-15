class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for(auto c : s)
            mpp[c]++;
        
        vector<pair<int, char>> v;
        for(auto it : mpp)
        v.push_back({it.second, it.first});

        sort(v.begin(), v.end(), greater<>());
        string ans = "";
        for(auto p : v)
            ans.append(p.first, p.second);
        return ans;
    }
};