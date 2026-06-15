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
    int totalTilt = 0;

    int findSum(struct TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = findSum(root->left);
        int right = findSum(root->right);

        totalTilt += abs(left - right);

        return left + right + root->val;
    }

    int findTilt(struct TreeNode* root) {
        totalTilt = 0;
        findSum(root);
        return totalTilt;
    }
};