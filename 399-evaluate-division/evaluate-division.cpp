class DisjointSet{
    public:
        vector<int> parent, size;
        vector<double> weight;
        DisjointSet(int n)
        {
            parent.resize(n+1);
            weight.resize(n+1, 1.0);
            size.resize(n+1, 1);
            for(int i = 0; i < n + 1; i++)
                parent[i] = i;
        }

        int findUpar(int u)
        {
            if(parent[u] == u)
                return u;
            int p = parent[u];
            parent[u] = findUpar(parent[u]);
            weight[u] *= weight[p];
            return parent[u];
        }

        void unite(int x, int y, double relation) {
            int rootX = findUpar(x);
            int rootY = findUpar(y);

            if (rootX == rootY)
                return;

            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;

                // rootX / rootY
                weight[rootX] = relation * weight[y] / weight[x];

                size[rootY] += size[rootX];
            }
            else {
                parent[rootY] = rootX;

                // rootY / rootX
                weight[rootY] = weight[x] / (relation * weight[y]);

                size[rootX] += size[rootY];
            }
        }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> id;
        int idx = 0;
        for(auto & it : eq)
        {
            if(!id.count(it[0]))
                id[it[0]] = idx++;
            if(!id.count(it[1]))
                id[it[1]] = idx++;
        }
        DisjointSet ds(idx);
        for(int i = 0; i < eq.size(); i++)
        {
            int u = id[eq[i][0]];
            int v = id[eq[i][1]];
            ds.unite(u, v, values[i]);
        }

        vector<double> ans;
        for(auto &it : queries)
        {
            if(!id.count(it[0]) || !id.count(it[1]))
            {
                ans.push_back(-1.000);
                continue;
            }
            if(ds.findUpar(id[it[0]]) != ds.findUpar(id[it[1]]))
                ans.push_back(-1.000);
            else
                ans.push_back(ds.weight[id[it[0]]] / ds.weight[id[it[1]]]);
        }
        return ans;
    }
};