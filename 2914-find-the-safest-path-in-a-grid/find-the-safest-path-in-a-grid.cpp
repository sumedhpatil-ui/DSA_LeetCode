class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();   
        if(grid[0][0] || grid[n-1][n-1])
            return 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int newr = dr[i] + row;
                int newc = dc[i] + col;
                if(newr < n && newr >= 0 && newc < n && newc >= 0 && !grid[newr][newc])
                {
                    grid[newr][newc] = grid[row][col] + 1;
                    q.push({newr, newc});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});  //{safety factor, row, col}

        while(!pq.empty())
        {
            auto [sf, row, col] = pq.top();
            pq.pop();

            if(row == n - 1 && col == n - 1)
                return sf - 1;
                
            for(int i = 0 ; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(min(newr, newc) >= 0 && max(newr, newc) < n && grid[newr][newc] > 0)
                {
                    pq.push({min(grid[newr][newc], sf), newr, newc});
                    grid[newr][newc] = -1;
                }
            }
        }
        return 0;
    }
};