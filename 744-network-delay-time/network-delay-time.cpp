class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times)
            adj[it[0]].push_back({it[1], it[2]});

        vector<int> dist(n+1, 1e9);
        priority_queue< pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > q;
        q.push({0, k});
        dist[k] = 0;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();

            int pathLen = it.first;
            int node = it.second;

            for(auto it : adj[node])
            {
                if(dist[it.first] > pathLen + it.second)
                {
                    dist[it.first] = pathLen + it.second;
                    q.push({dist[it.first], it.first});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < n+1; i++)
        {
            if(dist[i] == 1e9)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};