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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* one_step, *two_step;
        one_step = head;
        two_step = head;
        while(two_step != NULL && two_step->next != NULL)
        {
            one_step = one_step->next;
            two_step = two_step->next;
            if(two_step->next != NULL)
                two_step = two_step->next;
        }
        return one_step;
    }
};