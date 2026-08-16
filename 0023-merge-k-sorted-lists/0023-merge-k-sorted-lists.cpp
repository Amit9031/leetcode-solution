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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            ListNode* l=lists[i];
            while(l!=NULL){
                v.push_back(l->val);
                l=l->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode* lk=new ListNode(0);
        ListNode* temp=lk;
        for(auto it: v){
            temp->next=new ListNode(it);
            temp=temp->next;
        }
        return lk->next;
    }
};