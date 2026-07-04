class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionBySize(int u, int v)
    {
        int upar_u = uPar(u);
        int upar_v = uPar(v);

        if(upar_u == upar_v)
            return;
        if(size[upar_u] > size[upar_v])
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
        else
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
    }

    int uPar(int u)
    {
        if(parent[u] == u)
            return u;
        return parent[u] = uPar(parent[u]);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n + 1);
        int ans = INT_MAX;
        for(auto it : roads)
        {
            ds.unionBySize(it[0], it[1]);
        }

        if(ds.uPar(1) != ds.uPar(n))
            return -1;
        int root = ds.uPar(1);
        for(auto it : roads)
        {
            if(ds.uPar(it[0]) == root)
                ans = min(ans, it[2]);
        }
        return ans;
    }
};