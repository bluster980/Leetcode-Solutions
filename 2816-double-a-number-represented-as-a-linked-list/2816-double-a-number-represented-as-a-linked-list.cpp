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
    ListNode* doubleIt(ListNode* head) {
        ListNode *temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        reverse(v.begin(),v.end()); int carry = 0;
        for(int i=0; i<v.size(); i++){
            carry += v[i]*2;
            v[i] = carry%10;
            carry/=10;
        }
        if(carry > 0) v.push_back(carry);
        ListNode *heads = new ListNode(999);
        ListNode *dumy = heads;
        // dumy = dumy->next;
        reverse(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            dumy->next = new ListNode(v[i]);
            dumy = dumy->next;
        }
        // dumy = NULL;
        return heads->next;
    }
};