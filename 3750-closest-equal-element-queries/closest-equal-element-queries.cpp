class Solution {
public:
    int binSearch(vector<int> & arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        } 
        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < n; i++)
        {
           mp[nums[i]].push_back(i);
        }

        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++)
        {
            int ele = nums[queries[i]];
            vector<int>& arr = mp[ele];
            int mpIndex = binSearch(arr, queries[i]);
            int sz = arr.size();
            if(sz == 1)
            {
                ans[i] = -1;
                continue;
            }
            int prev = arr[(mpIndex - 1 + sz) % sz];
            int next = arr[(mpIndex + 1) % sz];
            int d1 = abs(arr[mpIndex] - prev);
            d1 = min(d1, n - d1);

            int d2 = abs(next - arr[mpIndex]);
            d2 = min(d2, n - d2);

            ans[i] = min(d1, d2);
        }
        return ans;
    }
};
