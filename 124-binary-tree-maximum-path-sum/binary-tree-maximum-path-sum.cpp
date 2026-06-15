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
int max_sum(TreeNode* root, int* sum)
{
    if(root == NULL)    return 0;
    int left = max(0, max_sum(root->left, sum));
    int right = max(0, max_sum(root->right, sum));

    *sum = max(*sum, left + right + root->val);
    return max(left, right) + root->val; 
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        max_sum(root, &sum);
        return sum;
    }
};