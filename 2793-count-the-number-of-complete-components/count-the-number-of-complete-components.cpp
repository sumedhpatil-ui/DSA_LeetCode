class DisjointSet{
public:
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUpar(int u)
    {
        if(parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int u_par = findUpar(u);
        int v_par = findUpar(v);

        if(u_par == v_par)
            return;
        if(size[u_par] < size[v_par])
        {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
        else
        {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        unordered_map<int, int> nodes;
        unordered_map<int, int> edgeCount;

        for(auto &it : edges)
        {
            ds.unionBySize(it[0], it[1]);
        }
        for(int i = 0; i < n; i++)
            nodes[ds.findUpar(i)]++;

        for(auto &it : edges)
        {
            int p = ds.findUpar(it[0]);
            edgeCount[p]++;
        }
        int ans = 0;

        for(auto [parent, v] : nodes)
        {
            int e = edgeCount[parent];
            if( e == (1LL * v *(v - 1) / 2) )
                ans++;
        }
        return ans;
    }
};