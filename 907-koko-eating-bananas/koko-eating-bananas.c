int required_time(int arr[], int hourly, int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (arr[i] + hourly - 1) / hourly; 
    }
    return ans;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = piles[0];

    for(int i = 1; i < pilesSize; i++)
        if(piles[i] > high)
            high = piles[i];

    while(low < high)
    {
        int mid = low + (high - low) / 2;
        int time = required_time(piles, mid, pilesSize);

        if(time <= h)
            high = mid;        
        else
            low = mid + 1;
    }
    return low;
}
