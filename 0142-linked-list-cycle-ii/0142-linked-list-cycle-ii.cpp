/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* extra = head,*fast=head,*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(extra != slow){
                    extra = extra->next;
                    slow = slow->next;
                }
                return extra;
            }
        }
        return NULL;
    }
};