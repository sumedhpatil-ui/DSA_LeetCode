class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        
        while (curr) {
            Node dummy(0);
            Node* tail = &dummy;
            
            // Traverse current level
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // move horizontally
            }
            
            // Move to next level
            curr = dummy.next;
        }
        
        return root;
    }
};