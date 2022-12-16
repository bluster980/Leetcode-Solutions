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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(); ListNode* dy = ans,*ly;
        stack<int> st,st2;
        ListNode* temp=l1,*temp2=l2;
        int sum = 0;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        while(temp2!=NULL){
            st2.push(temp2->val);
            temp2=temp2->next;
        }
        while(!st.empty() || !st2.empty()){
            if(!st.empty()){
                sum += st.top(); st.pop();
            }
            if(!st2.empty()){
                sum += st2.top(); st2.pop();
            }
            dy->val = sum%10; dy->next = new ListNode(); ly=dy; dy=dy->next;
            if(sum > 9) sum/=10;
            else sum=0;
        }
        if(sum > 0) {dy->val = sum; ly=dy; dy=dy->next;}
        ly->next = NULL;
        
        ListNode* prev=NULL,*cur=ans,*forw=cur->next;
        while(forw!=NULL){
            cur->next = prev;
            prev = cur; cur = forw; forw = forw->next;
        }cur->next = prev;  
        return cur;
    }
};