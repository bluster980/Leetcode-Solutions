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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *s1 = headA, *s2 = headB;
        while(s1 != NULL && s2 != NULL){
            s1 = s1->next; s2 = s2->next;
        }
        ListNode *e1,*e2;
        if(s1 == NULL){
            e1 = headB;
            while(s2 != NULL){
                s2 = s2->next; e1 = e1->next;
            }
            e2 = headA;
            while(e1 != e2){
                e1 = e1->next;
                e2 = e2->next;
            }
        }
        else{
            e1 = headA;
            while(s1 != NULL){
                s1 = s1->next; e1 = e1->next;
            }
            e2 = headB;
            while(e1 != e2){
                e1 = e1->next;
                e2 = e2->next;
            }
        }
        return e1;
    }
};