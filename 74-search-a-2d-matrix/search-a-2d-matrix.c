bool searchMatrix(int** matrix, int n, int* m, int target) {
    int low = 0;
    int high = n*(*m) - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / (*m), column = mid % (*m);
        if(matrix[row][column] == target) return true;
        else if(matrix[row][column] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}