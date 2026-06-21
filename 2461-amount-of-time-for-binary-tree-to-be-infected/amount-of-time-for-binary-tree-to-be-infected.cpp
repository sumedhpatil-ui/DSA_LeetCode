/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void build(TreeNode* root, unordered_map<int, vector<int>>& adj)
    {
        if(root == NULL)
            return ;
        int rootVal = root->val;
        int v;
        if(root->left)
        {   
            v = root->left->val;
            adj[rootVal].push_back(v);
            adj[v].push_back(rootVal);
            build(root->left, adj);
        }
        if(root->right)
        {
            v = root->right->val;
            adj[rootVal].push_back(v);
            adj[v].push_back(rootVal);
            build(root->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        build(root, adj);
        unordered_map<int, bool> vis;
        queue<pair<int, int>> q;
        int ans  = 0;
        q.push({start, 0});
        vis[start] = true;
        while(!q.empty())
        {
            int node = q.front().first;
            int count = q.front().second;
            q.pop();

            for(auto adjNode : adj[node])
            {
                bool flag = false;
                if(!vis[adjNode])
                {
                    vis[adjNode] = true;
                    q.push({adjNode, count + 1});
                    flag = true;
                }
                if(!flag) ans = max(ans, count);
            }
        }
        return ans;
    }
};