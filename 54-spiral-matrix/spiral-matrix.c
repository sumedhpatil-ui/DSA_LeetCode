/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int *ans = malloc(sizeof(int) * rows * cols);
    *returnSize = rows * cols;
    int k = 0;
    int top = 0, bottom = matrixSize -1;
    int left = 0, right = * matrixColSize -1;
    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            ans[k] = matrix[top][i];
            k++;
        }
        top++;
        for(int i = top; i <= bottom; i++)
        {
            ans[k] = matrix[i][right];
            k++;
        }
        right--;
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                ans[k] = matrix[bottom][i];
                k++;
            }
            bottom--;
        }
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans[k] = matrix[i][left];
                k++;
            }
            left++;
        }
    }
    return ans;
}