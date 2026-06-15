class Solution {
public: 
    int n, m;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        int ans = 1;
        grid[row][col] = 0;

        for(int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 1)
            {
                ans += dfs(grid, nrow, ncol);
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int temp = dfs(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};