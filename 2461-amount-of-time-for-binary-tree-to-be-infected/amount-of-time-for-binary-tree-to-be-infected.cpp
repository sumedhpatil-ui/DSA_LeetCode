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
    int dfs(TreeNode* root, int start, int* ans)
    {
        if(root == NULL)
            return 0;
        int leftHt = dfs(root->left, start, ans);
        int rightHt = dfs(root->right, start, ans);

        if(root->val == start)
        {
            *ans = max(leftHt, rightHt);
            return -1;
        }
        else if(leftHt >= 0 && rightHt >= 0)
            return max(leftHt, rightHt) + 1;
        else
        {
            *ans = max(*ans, abs(leftHt) + abs(rightHt));
            return min(leftHt, rightHt) - 1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL)
            return 0;
        int ans = 0;
        dfs(root, start, &ans);
        return ans;
    }
};