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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode* front = head;
        for(int i = 0; i < n; i++)
        {
            front = front->next;
        }
        if(front == NULL)
            return head->next;
        ListNode* rear = head;
        while(front->next != NULL)
        {
            rear = rear->next;
            front = front->next;       
        }
        front = rear->next;
        rear->next = front->next;
        return head;
    }
};