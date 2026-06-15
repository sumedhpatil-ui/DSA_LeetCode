class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};
    int n;
    int m;
    bool dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, string& word, int c)
    {
        vis[row][col] = 1;
        if(c == word.size())
            return true;
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[c])
                if(dfs(nrow, ncol, vis, board, word, c+1))
                    return true;
        }
        vis[row][col]= 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if(dfs(i, j, vis, board, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};