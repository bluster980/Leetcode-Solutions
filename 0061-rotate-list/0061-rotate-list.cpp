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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int count = 1; ListNode* slow=head,*dumy;
        while(slow->next!=NULL){
            slow=slow->next;
            count++;
        }
        k%=count;
        if(k==0) return head;
        if(k>0) slow->next=head;
        int tep=count-k;
        while(tep--){
            slow=slow->next;
        }
        // slow=slow->next;
        dumy=slow->next;
        slow->next=NULL;
        return dumy;
    }
};