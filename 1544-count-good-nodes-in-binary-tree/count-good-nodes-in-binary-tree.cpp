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
    void helper(TreeNode* root, int max, int* ans)
    {
        if(root == NULL) 
            return;
        if(root->val >= max)
        {
            *ans =  (*ans) + 1;
            max = root->val;
        }    
        if(root->left)
            helper(root->left, max, ans);
        if(root->right)
            helper(root->right, max, ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        helper(root, root->val, &ans);
        return ans;
    }
};