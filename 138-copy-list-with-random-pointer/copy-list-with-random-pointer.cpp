/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;    //{old, new}
        Node* temp = head;
        while(temp != NULL)
        {
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        Node* newHead = mpp[head];
        temp = head;
        while(temp != NULL)
        {
            Node* newNode = mpp[temp];
            newNode->next = mpp[temp->next];
            newNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return newHead;
    }
};