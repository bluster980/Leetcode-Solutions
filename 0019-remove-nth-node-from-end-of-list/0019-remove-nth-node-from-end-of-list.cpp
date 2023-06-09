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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fi=head,*sd=head;
        
        while(n--){
            sd=sd->next;
        }
        if(sd==NULL) return head->next;
        while(sd->next!=NULL){
            sd=sd->next;
            fi=fi->next;
        }
        fi->next=fi->next->next;
        
        return head;
    }
};