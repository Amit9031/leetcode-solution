/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root)return false;
        
        if(key<root->data){
           return  search(root->left, key);
        }
        if(key>root->data){
           return  search(root->right, key);
        }
        return true;
    }
};