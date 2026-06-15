class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int perimeter = 0;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {-1, 0, 1, 0};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int newr = i + dr[k];
                        int newc = j + dc[k];

                        // water or outside grid
                        if(newr < 0 || newr >= n ||
                           newc < 0 || newc >= m ||
                           grid[newr][newc] == 0)
                        {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};