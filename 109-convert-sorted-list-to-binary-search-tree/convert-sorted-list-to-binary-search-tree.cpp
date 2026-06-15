class Solution {
public:

    ListNode* findMid(ListNode* left, ListNode* right) {
        ListNode* slow = left;
        ListNode* fast = left;

        while(fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode* build(ListNode* left, ListNode* right) {
        if(left == right) return NULL;

        ListNode* mid = findMid(left, right);
        TreeNode* root = new TreeNode(mid->val);

        root->left = build(left, mid);
        root->right = build(mid->next, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, NULL);
    }
};