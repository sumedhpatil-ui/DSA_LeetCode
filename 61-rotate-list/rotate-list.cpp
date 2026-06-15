class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

    
        temp->next = head;

        k = k % n;
        int steps = n - k;

        ListNode* newTail = temp;
        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};