class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
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
    int findUpar(int n){
        if(parent[n] == n)
            return n;
        return parent[n] = findUpar(parent[n]);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int rowMax = INT_MIN;
        int colMax = INT_MIN;

        for(auto &it : stones)
        {
            rowMax = max(it[0], rowMax);
            colMax = max(it[1], colMax);
        }
        DisjointSet ds(rowMax + colMax + 2);
        unordered_map<int, int> mpp;
        
        for(auto &it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + rowMax + 1;

            mpp[rowNode] = 1;
            mpp[colNode] = 1;
            ds.unionBySize(rowNode, colNode);
        }
        int cnt = 0;
        for(auto &it : mpp)
        {
            if(ds.findUpar(it.first) == it.first)
                cnt++;
        }
        return stones.size() - cnt;
    }
};