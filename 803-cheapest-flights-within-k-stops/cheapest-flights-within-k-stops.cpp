class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;

        // {stops, {node, cost}}

        vector<int> dist(n, 1e9);

        q.push({0, {src, 0}});

        dist[src] = 0;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)
                continue;

            for(auto nbr : adj[node])
            {
                int adjNode = nbr.first;
                int edgeWt = nbr.second;

                if(cost + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = cost + edgeWt;

                    q.push({
                        stops + 1,
                        {adjNode, cost + edgeWt}
                    });
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};