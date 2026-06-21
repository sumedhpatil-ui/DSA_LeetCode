class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int, int>> adj[n]; // {    {node1 -> pair   } , {node2 -> pair}   }
        for(auto it : edges)
            adj[it[0]].push_back({it[1], it[2]});
        vector<vector<long long>> dis(n, vector<long long>(k+1, 1e9));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;    // {weigth, node, occurance}
        pq.push({0, 0, 1});
        dis[0][1] = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long weight = it[0];
            int node = it[1];
            int occ = it[2];

            if(node == n -1)
                return weight;

            for(auto [adjNode, edw] : adj[node])
            {
                int newOcc;
                if(labels[adjNode] == labels[node])
                {
                    newOcc = occ + 1;
                    if(newOcc > k)
                        continue;
                }
                else
                {
                    newOcc = 1;
                }
                long long newEdge = edw + weight;
                if(dis[adjNode][newOcc] > newEdge)
                {
                    dis[adjNode][newOcc] = newEdge;
                    pq.push({newEdge, adjNode, newOcc});
                }
            }
        }
        return -1;
    }
};