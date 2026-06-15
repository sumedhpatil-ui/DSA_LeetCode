class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        int total = 0;
        vector<vector<int>> vis (n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                    total++;
                if((i == 0 || i == n-1 || j == 0 || j == m-1)&& board[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {-1, 0, 1, 0};
        count = q.size();
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && !vis[nrow][ncol] && board[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    count++;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return total - count;
    }
};