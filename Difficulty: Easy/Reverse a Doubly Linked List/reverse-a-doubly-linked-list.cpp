class Solution {
public:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to next node (original next)
            curr = curr->prev;
        }

        // temp points to previous node of NULL
        return temp->prev;
    }
};