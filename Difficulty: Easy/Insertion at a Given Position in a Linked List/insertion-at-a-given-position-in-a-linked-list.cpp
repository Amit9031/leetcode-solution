/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
      
      Node* newNode=new Node(val);
      if(pos==1){
          newNode->next=head;
          return newNode;
      }
      
         Node* temp= head;
         
         int count=1;
         while(temp!=NULL  && count<pos-1){
             temp=temp->next;
             count++;
         }
         if(temp==NULL)return head;
         
         newNode->next=temp->next;
         temp->next=newNode;
         
    
            
        return head;
    }
};