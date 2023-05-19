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
        // if(list1==NULL) return list2;
        // if(list2==NULL) return list1; 
        ListNode* head,*temp = new ListNode(), *i=list1, *j=list2;
        // if(i->val < j->val){
        //     temp = i; i=i->next;
        // }
        // else{
        //     temp = j; j=j->next;
        // }
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
        // if(i==NULL) temp->next=j;
        // else if(j==NULL) temp->next=i;
        return head->next;
    }
};