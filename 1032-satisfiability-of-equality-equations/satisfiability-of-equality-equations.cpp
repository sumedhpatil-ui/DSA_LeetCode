class DisjointSet{
    public:
        vector<int> parent;
        vector<int> size;
        DisjointSet(int n)
        {
            parent.resize(n);
            size.resize(n);

            for(int i = 0; i< n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        void unionBySize(int u, int v)
        {
            int u_par = findUpar(u);
            int v_par = findUpar(v);
            if(u_par == v_par)
                return;
            if(size[u_par] > size[v_par])
            {
                size[u_par] += size[v_par];
                parent[v_par] = u_par;
            }
            else
            {
                size[v_par] += size[u_par];
                parent[u_par] = v_par;
            }
        }
        int findUpar(int u)
        {
            if(parent[u] == u)
                return u;
            return parent[u] = findUpar(parent[u]);
        }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto it : equations)
        {
            if(it[1] == '=')
            {
                ds.unionBySize(it[0] - 'a', it[3] - 'a');
            }
        }

        for(auto it : equations)
        {
            if(it[1] == '!')
            {
                if(ds.findUpar(it[0] - 'a') == ds.findUpar(it[3] - 'a'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};