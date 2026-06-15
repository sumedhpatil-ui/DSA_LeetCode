/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        ListNode* slowPrev = NULL;
        while(fast->next != NULL)
        {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL)
                fast = fast->next;
        }
        if(slowPrev == NULL)
        {
            slow->next = NULL;
            return slow;
        }
        slowPrev->next = slow->next;
        return head;
    }
};