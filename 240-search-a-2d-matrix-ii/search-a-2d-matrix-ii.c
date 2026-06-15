bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    int column = *matrixColSize -1;
    while(row < matrixSize && column >= 0)
    {
        if(matrix[row][column] == target)
            return true;
        else if(matrix[row][column] < target)
            row++;
        else 
            column--;
    }
    return false;
}