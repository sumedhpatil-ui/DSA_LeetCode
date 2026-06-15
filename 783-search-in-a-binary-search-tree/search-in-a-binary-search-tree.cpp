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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result, *current;
        result = NULL;
        current = root;
        int flag = 0;
        while(current != NULL && flag == 0)
        {
            if(val > current->val)
            {
                current = current->right;
            }
            else if(val < current->val)
                current = current->left;
            else 
            {
                result = current;
                flag = 1;
            }
        }
        return result;
    }
};