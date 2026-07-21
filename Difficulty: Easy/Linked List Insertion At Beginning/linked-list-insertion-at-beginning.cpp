/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node* neww=new Node(x);
        
        if(head){
            neww->next=head;
            head=neww;
            
        }
        return head;
    }
};