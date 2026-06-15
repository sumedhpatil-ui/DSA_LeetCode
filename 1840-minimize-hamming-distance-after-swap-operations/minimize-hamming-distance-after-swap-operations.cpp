class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& comp, vector<int>& visited) {
        visited[node] = 1;
        comp.push_back(node);

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, comp, visited);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        // Step 1: Build graph
        vector<vector<int>> adj(n);
        for (auto &e : allowedSwaps) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        int result = 0;

        // Step 2: Find components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> comp;
                dfs(i, adj, comp, visited);

                // Step 3: Frequency map for this component
                unordered_map<int, int> freq;

                // Count source values
                for (int idx : comp) {
                    freq[source[idx]]++;
                }

                // Match target values
                for (int idx : comp) {
                    if (freq[target[idx]] > 0) {
                        freq[target[idx]]--;
                    } else {
                        result++; // mismatch
                    }
                }
            }
        }

        return result;
    }
};