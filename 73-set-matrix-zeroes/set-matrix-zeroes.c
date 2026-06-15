void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i;
    int j;
    int pre_col = 1;
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < * matrixColSize; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    pre_col = 0;
            }
        }
    }
    for(i = 1; i < matrixSize; i++)
    {
        for(j = 1; j < * matrixColSize; j++)
        {
            if(matrix[i][j] != 0)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0)
    {
        for(j = 1; j < * matrixColSize; j++)
        {
            matrix[0][j] = 0;   
        }
    }
    if(pre_col == 0)
    {
        for(i = 0; i < matrixSize; i++)
        {
            matrix[i][0] = 0;
        }
    }
}