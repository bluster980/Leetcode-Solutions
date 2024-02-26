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
    ListNode *middle(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* mergeSorted(ListNode *l1, ListNode *l2){
        ListNode *head = new ListNode(0), *curr = head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                curr->next = l1; curr=curr->next; l1 = l1->next;
            }
            else{
                curr->next = l2; curr=curr->next; l2 = l2->next;
            }
        }
        if(l1 == NULL) curr->next = l2;
        else curr->next = l1;
        return head->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *mid = middle(head);
        ListNode *shalf = mid->next;
        mid->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(shalf);
        return mergeSorted(left,right);
    }
};