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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head,*temp = new ListNode(), *i=list1, *j=list2;
        head = temp;
        while(i!=NULL && j!=NULL){
            if(i!=NULL && i->val <= j->val){
                temp->next = i; i=i->next;
            }
            else if(j!=NULL && j->val < i->val){
                temp->next = j; j=j->next;
            }
            temp = temp->next;
        }
        temp->next = (i==NULL)?j:i;
        return head->next;
    }
};