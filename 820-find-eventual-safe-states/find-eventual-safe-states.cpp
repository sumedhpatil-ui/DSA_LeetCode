class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis,
             vector<int>& check, int i) {
        vis[i] = 1;
        pathvis[i] = 1;
        for (auto it : graph[i]) {
            if (!vis[it]) {
                if (dfs(graph, vis, pathvis, check, it)) 
                {
                    check[it] = 0;
                    return true;
                } 
            }
            else if (pathvis[it])
                return true;
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, vis, pathvis, check, i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i] == 1)
                result.push_back(i);
        }
        return result;
    }
};