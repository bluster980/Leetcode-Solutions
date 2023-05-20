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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode *fast=head,*slow=head,*prev=NULL,*forw=head,*curr=head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            forw = forw->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        if(fast!=NULL) slow=slow->next;
        while(prev!=NULL && slow!=NULL && prev->val==slow->val){
            prev=prev->next; slow=slow->next;
        }
        return (prev==NULL && slow==NULL);
    }
};