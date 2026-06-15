void merge_self(int a[], int lo, int mid, int hi)
{
    int size = hi - lo + 1;
    int c[size];

    int i = lo, j = mid + 1, k = 0;

    while(i <= mid && j <= hi)
    {
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while(i <= mid)
        c[k++] = a[i++];

    while(j <= hi)
        c[k++] = a[j++];

    // copy back to original
    for(int p = 0; p < size; p++)
        a[lo + p] = c[p];
}

void merge_sort(int a[], int lo, int hi)
{
    if(lo >= hi) return;

    int mid = lo + (hi - lo) / 2;

    merge_sort(a, lo, mid);
    merge_sort(a, mid + 1, hi);

    merge_self(a, lo, mid, hi);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* a = (int*)malloc(numsSize * sizeof(int));
    if(!a) return NULL;

    for(int i = 0; i < numsSize; i++)
        a[i] = nums[i];

    merge_sort(a, 0, numsSize - 1);

    return a;
}
