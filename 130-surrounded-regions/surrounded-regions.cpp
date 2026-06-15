class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis (n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 || i == n-1 || j == 0 || j == m-1)&& board[i][j] == 'O')
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {-1, 0, 1, 0};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};