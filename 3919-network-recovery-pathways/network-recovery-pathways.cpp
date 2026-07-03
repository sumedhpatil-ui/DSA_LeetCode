class Solution {
public:
    bool checkCost(vector<vector<pair<int, int>>> & adj, int cost, long long k, int n)
    {
        vector<long long> dist(n, LLONG_MAX);
       priority_queue<tuple<long long,int>, vector<tuple<long long,int>>, greater<tuple<long long,int>>> pq;   //{cost, node}
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty())
        {
            auto [c, node] = pq.top();
            pq.pop();

            if(c > dist[node])
                continue;
            if(c > k)
                break;
            if(node == n - 1)            
                return true;

            for(auto it : adj[node])
            {
                long long adjCost = c + it.second;
                if(it.second < cost)
                    continue;
                if(adjCost < dist[it.first])
                {
                    dist[it.first] = adjCost; 
                    pq.push({adjCost, it.first});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int low = INT_MAX;
        int high = INT_MIN;
        int ans = -1;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(!online[u] || !online[v])
                continue;
            adj[u].push_back({v, w});
            low = min(low, w);
            high = max(high, w);
        }

        if(low == INT_MAX)  return -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(checkCost(adj, mid, k, n))
            {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};