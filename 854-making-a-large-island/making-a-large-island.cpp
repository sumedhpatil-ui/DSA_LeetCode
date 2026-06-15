class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int findUpar(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findUpar(parent[n]);
    }
};

class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    bool isvalid(int row, int col, int n)
    {
        if(row >= 0 && row < n && col < n && col >= 0)
            return true;
        return false;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 0)
                    continue;
                for(int k = 0; k < 4; k++)
                {
                    int adjr = row + dr[k];
                    int adjc = col + dc[k];
                    if(isvalid(adjr, adjc, n) && grid[adjr][adjc] == 1)
                    {
                        int adjNode = adjr * n + adjc;
                        int currNode = row * n + col;
                        ds.unionBySize(adjNode, currNode);
                    }
                }
            }
        }  
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                set<int> components;
                if(grid[i][j] == 1)
                    continue;
                for(int k = 0; k < 4; k++)
                {
                    int newR = i + dr[k];
                    int newC = j + dc[k];

                    if(isvalid(newR, newC, n) && grid[newR][newC] == 1)
                    {
                        int newNode = newR * n + newC;
                        components.insert(ds.findUpar(newNode));
                    }
                }
                long long currArea = 0;
                for(auto &it : components)
                {
                    currArea += ds.size[it];
                }
                ans = max(ans, currArea + 1);
            }
        }
        for(int cellNo = 0; cellNo < n*n ; cellNo++)
        {
            ans = max(ans, (long long)ds.size[ds.findUpar(cellNo)]);
        }
        return ans;
    }
};
