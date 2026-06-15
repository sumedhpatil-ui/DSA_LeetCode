class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& image, int color)
    {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();

        int inicol = image[row][col];
        if(inicol == color) return;

        q.push({row, col});
        image[row][col] = color;      

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(c-1 >= 0 && image[r][c-1] == inicol)
            {
                image[r][c-1] = color;   
                q.push({r, c-1});
            }
            if(c+1 < m && image[r][c+1] == inicol) 
            {
                image[r][c+1] = color;
                q.push({r, c+1});
            }
            if(r-1 >= 0 && image[r-1][c] == inicol) 
            {
                image[r-1][c] = color;
                q.push({r-1, c});
            }
            if(r+1 < n && image[r+1][c] == inicol) 
            {
                image[r+1][c] = color;
                q.push({r+1, c});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(sr, sc, image, color);
        return image;
    }
};