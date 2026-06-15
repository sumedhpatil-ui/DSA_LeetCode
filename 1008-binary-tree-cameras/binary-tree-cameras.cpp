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
//return 1 if it is a intermediate node that has camera'
//return 0 if it is a node where camera is needed
// return 2 if it is covered by the camera of parent
class Solution {
public:
    int camera = 0;
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 2; //child of leaf

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 0 || right == 0)
        {
            camera++;
            return 1;
        }
        if(left == 1 || right == 1)
            return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        camera = 0;
        if(dfs(root) == 0)
            camera++;
        return camera;
    }
};