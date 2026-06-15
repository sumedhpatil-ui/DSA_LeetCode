int req_day(int arr[], int n, int cap, int days)
{
    int d = 1, load = 0;

    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > cap)
        {
            d++;
            load = arr[i];
            if (d > days) return d;   // early exit
        }
        else
            load += arr[i];
    }
    return d;
}

int shipWithinDays(int* w, int n, int days)
{
    int low = 0, high = 0;

    for (int i = 0; i < n; i++)
    {
        if (w[i] > low) low = w[i];
        high += w[i];
    }

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (req_day(w, n, mid, days) <= days)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
