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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i-1] <= maxDiff)
            {
                ds.unionBySize(i, i-1);
            }
        }

        vector<bool> ans;
        for(auto it : queries)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findUpar(u) == ds.findUpar(v))
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
};