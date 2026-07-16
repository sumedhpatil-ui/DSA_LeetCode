class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n)
        {
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i = 0; i < n + 1; i++)
                parent[i] = i;
        }

        int findUpar(int n)
        {
            if(parent[n] == n)
                return n;
            return parent[n] = findUpar(parent[n]);
        }

        void unionBySize(int u, int v)
        {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v)
                return;
            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }   
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for(auto &it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        DisjointSet ds(n);
        for(int i = 1; i <= n; i++)
        {
            if(adj[i].empty())  continue;

            int first = adj[i][0];
            for(int &v : adj[i])
            {
                if(ds.findUpar(i) == ds.findUpar(v))
                    return false;
                ds.unionBySize(v, first);
            }
        }
        return true;
    }
};