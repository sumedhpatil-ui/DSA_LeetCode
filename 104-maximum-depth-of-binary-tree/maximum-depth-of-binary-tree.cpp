void helper(TreeNode* root, int curr, int* maxDepth)
{
    if(root == NULL)
        return;

    if(curr > *maxDepth)
        *maxDepth = curr;

    helper(root->left, curr + 1, maxDepth);
    helper(root->right, curr + 1, maxDepth);
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int maxDepth = 1;
        helper(root, 1, &maxDepth);
        return maxDepth;
    }
};
