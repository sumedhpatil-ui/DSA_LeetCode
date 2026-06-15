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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverseList(slow);
        slow = newhead;
        fast = head;
        while(slow != NULL)
        {
            if(slow->val != fast->val)
            {
                reverseList(newhead);
                return false;
            }
            else
            {
                slow = slow->next;
                fast = fast->next;

            }
        }
        reverseList(newhead);
        return true;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* front, *mid, *tail;
        front = NULL;
        mid = head;
        tail = NULL;
        while(mid != NULL)
        {
            front = mid->next;
            mid->next = tail;
            tail = mid;
            mid = front;
        }
        return tail;
    }
};