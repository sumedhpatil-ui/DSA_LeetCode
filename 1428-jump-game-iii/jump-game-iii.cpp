class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(arr[node] == 0)
                return true;

            int front = node + arr[node];
            int back = node - arr[node];
            if(front < n && front >= 0 && !vis[front])
            {
                vis[front] = 1;
                q.push(front);
            }

            if(back >= 0 && back < n && !vis[back])
            {
                vis[back] = 1;
                q.push(back);
            }    
        }
        return false;
    }
};