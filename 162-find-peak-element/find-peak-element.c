int findPeakElement(int* nums, int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid + 1])
            high = mid;      // peak is on left side (including mid)
        else
            low = mid + 1;   // peak is on right side
    }
    return low;
}
