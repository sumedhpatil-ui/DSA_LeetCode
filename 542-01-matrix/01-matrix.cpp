class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    if(dis[nrow][ncol] > dis[row][col] + 1)
                    {
                        dis[nrow][ncol] = dis[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return dis;
    }
};