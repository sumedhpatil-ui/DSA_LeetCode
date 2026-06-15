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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findUpar(u) == ds.findUpar(v))
                return {u, v};
            ds.unionBySize(u, v);
        }
        return {};
    }
};