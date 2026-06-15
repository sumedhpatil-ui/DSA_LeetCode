class Solution {
public:
    struct store{
        int d, x, y ;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<store> q;
        q.push({0,0,0});
        int ans = INT_MAX;
        int dx[8]= {0,0,-1,1,1,-1,-1,1};
        int dy[8]= {-1,1,0,0,1,-1,1,-1};

        while(!q.empty()){
            auto tp = q.front(); q.pop();
            int d = tp.d;
            int x = tp.x;
            int y = tp.y;
            if(x == grid.size()-1 && y == grid[0].size()-1) ans = min(ans, d + 1);
            for(int i = 0; i < 8; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx >= 0 && nx < grid.size() && 
                ny >= 0 && ny < grid[0].size() && 
                grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    q.push({d + 1 , nx, ny});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};