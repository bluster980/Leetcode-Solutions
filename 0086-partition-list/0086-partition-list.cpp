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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *ans = head;
        for(int i=0; i<v.size(); i++){
            if(v[i] < x){
                ans->val = v[i];
                ans = ans->next;
            }
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] >= x){
                ans->val = v[i];
                ans = ans->next;
            }
        }
        return head;
    }
};