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
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode *fast=head,*slow=head,*temp=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL) slow=slow->next;
        ListNode *prev=NULL,*curr=slow,*forw=slow->next;
        slow = NULL;
        while(forw!=NULL){
            curr->next=prev;
            prev=curr;
            curr=forw;
            forw=forw->next;
        }
        curr->next=prev;
        ListNode *st=head,*en=curr,*pst,*pen;
        while(st!=NULL){
            pst=st;
            st=st->next;
            pen=en;
            if(en!=NULL){
                en=en->next;
            }
            pst->next=pen;
            if(pen!=NULL)
                pen->next=st;
            if(pen==NULL) break;
            // pen=en;
            // en=en->next;
            
            // if(en!=NULL){
            //     en=en->next;
            // }
            // pst=st;
            // st=st->next;
            // pen->next=pst;
        }
        if(fast!=NULL) pst=st;
//         while(st!=NULL){
//             st->next=en;
//             st=st->next;
//             en->next=st;
//             en=en->next;
            
            // cout<<head->val<<" ";
            // st=head;
            // // head=head->next;
            // if(en!=NULL){
            //     st=en;
            //     en=en->next;
            //     // cout<<en->val<<" ";
            //     // en=en->next;
            // }
            // st=st->next;
        // }
        // while(head->next!=NULL){
        //     cout<<head->val<<" ";
        //     head=head->next;
        // }
        // cout<<endl;
        // while(curr!=NULL){
        //     cout<<curr->val<<" ";
        //     curr=curr->next;
        // }
        // cout<<endl;
    }
};