class Solution {
public:
    pair<int,int> getInterval(int start, vector<int> &first, vector<int> &last, string &s)
    {   
        int end = last[ s[start] - 'a'];
        for(int i = start; i <= end; i++)
        {
            if(first[s[i] - 'a'] < start)
            {
                return {-1, -1};
            }
            end = max(end, last[s[i] - 'a']);
        }
        return {start, end};
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if(first[idx] == -1)
            {
                first[idx] = i;
            }
            last[idx] = i;
        }
        int i = 0;
        vector<pair<int, int>> intervals;
        for(int i = 0; i < 26; i++)
        {
            if(first[i] != -1)
            {
                auto p = getInterval(first[i], first, last, s);
                if(p.first != -1)
                    intervals.push_back(p);
            }
        }
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
        {
            return a.second < b.second;
        });

        vector<string> ans;
        int prevEnd = -1;
        for(auto &it : intervals)
        {
            int l = it.first;
            int r = it.second;
            if(l > prevEnd)
            {
                ans.push_back(s.substr(l, r-l+1));  // substr(first index, length)
                prevEnd = r;
            }
        }
        return ans;
    }
};