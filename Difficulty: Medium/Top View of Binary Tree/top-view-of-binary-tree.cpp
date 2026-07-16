/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node* , int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto node=q.front().first;
            auto h=q.front().second;
            
            q.pop();
            
            if(mp.find(h)==mp.end()){
                mp[h]=node->data;
            }
            if(node->left)q.push({node->left,h-1});
            if(node->right)q.push({node->right, h+1});
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};