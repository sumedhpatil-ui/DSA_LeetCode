class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return {};
        vector<int> temp;
        for(auto &it : arr)
            temp.push_back(it);
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mpp;
        mpp[temp[0]] = 1;
        for(int i = 1; i < n; i++)
        {
            if(temp[i] != temp[i-1])
                mpp[temp[i]] = mpp[temp[i - 1]] + 1;
            else
                mpp[temp[i]] = mpp[temp[i-1]];
        }

        for(int i = 0; i < n; i++)
        {
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};