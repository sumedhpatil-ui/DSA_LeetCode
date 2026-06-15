class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) 
        {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (row == n - 1 && col == n - 1)
                return time;

            if (time > dist[row][col])
                continue;

            for (int k = 0; k < 4; k++) 
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (!isValid(nr, nc, n))
                    continue;

                int newTime = max(time, grid[nr][nc]);

                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }

        return -1;
    }
};