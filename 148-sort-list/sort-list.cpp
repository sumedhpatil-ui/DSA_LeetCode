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
    ListNode* sortList(ListNode* head) {
        ListNode* nptr, *lptr;
        lptr = head;
        if(lptr != NULL && lptr->next != NULL)
        {
            nptr = divide(lptr);
            lptr = sortList(lptr);
            nptr = sortList(nptr);
            head = mergeList(lptr, nptr);
        }
        return head;
    }
    ListNode* mergeList(ListNode* lptr, ListNode* nptr){
        ListNode* result;
        ListNode* ptr1, *ptr2, *tail;
        ptr1 = lptr;
        ptr2 = nptr;
        if(ptr1->val > ptr2->val)
        {
            result = ptr2;
            ptr2 = ptr2->next;
            tail = result;
        }
        else
        {
            result = ptr1;
            ptr1 = ptr1->next;
            tail = result;
        }
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1->val > ptr2->val)
            {
                tail->next = ptr2;
                tail = tail->next;
                ptr2 = ptr2->next;
            }
            else
            {
                tail->next = ptr1;
                tail = tail->next;
                ptr1 = ptr1->next;
            }
        }
        if(ptr1 != NULL)
            tail->next = ptr1;
        if(ptr2 != NULL)
            tail->next = ptr2;
        return result;
    }
    ListNode* divide(ListNode* lptr)
    {
        ListNode* slow, *fast, *nptr;
        slow = lptr;
        fast = lptr->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        nptr = slow->next;
        slow->next = NULL;
        return nptr;
    }
};