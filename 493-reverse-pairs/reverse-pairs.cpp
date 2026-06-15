class Solution {
public:
    int merge_sort(vector<int>& arr, int low, int high)
    {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int cnt = 0;

        cnt += merge_sort(arr, low, mid);
        cnt += merge_sort(arr, mid + 1, high);

        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long)arr[i] > 2LL * arr[j])
                j++;
            cnt += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};
