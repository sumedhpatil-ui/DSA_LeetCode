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
    bool search(TreeNode* root,TreeNode* cur, int k)
    {
        if(root == NULL)
            return false;
        if(k == root->val && root != cur)
            return true;
        if(k > root->val)
            return search(root->right, cur, k);
        else
            return search(root->left, cur, k);
        
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(search(root, cur, k - cur->val))
                return true;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return false;
    }
};