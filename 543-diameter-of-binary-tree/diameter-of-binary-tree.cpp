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
int diameter(TreeNode* root, int* maxi)
{
    if(root == NULL)    return 0;
    int left = diameter(root->left, maxi);
    int right = diameter(root->right, maxi);
    if(left + right > *maxi) *maxi = left + right;
    return max(left, right) + 1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameter(root, &dia);
        return dia;
    }
};