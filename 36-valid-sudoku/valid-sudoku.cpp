class Solution {
public:
    int n;
    bool traverseInPlus(vector<vector<char>>& board, int row, int col, char val)
    {
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == val && i != row) // check column
                return false;
            if(board[row][i] == val && i != col)
                return false;
        }
        return true;
    }

    bool boxTraversal(int row, int col, vector<vector<char>>& board, char val)
    {
        int nrow, ncol;
        if(row >= 0 && row <= 2)
            nrow = 0;
        else if(row >= 3 && row <= 5)
            nrow = 3;
        else
            nrow = 6;

        if(col >= 0 && col <= 2)
            ncol = 0;
        else if(col >= 3 && col <= 5)
            ncol = 3;
        else
            ncol = 6;
        
        for(int i = nrow; i < nrow + 3; i++)
        {
            for(int j = ncol; j < ncol + 3; j++)
            {
                if((i != row || j != col) && board[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        n = board.size();
        bool retval = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != '.')
                {
                    retval = traverseInPlus(board, i, j, board[i][j]) && boxTraversal(i, j, board, board[i][j]);
                    if(retval == false)
                        return false;
                }
            }
        }
        return retval;
    }
};