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
    ListNode* reverse(ListNode* left, ListNode* right, ListNode* forw){
        if(left == right){
            return left;
        }
        ListNode *newNode = reverse(left->next, right,forw);
        left->next->next = left;
        left->next = forw;
        return newNode;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* prev=head,*curr=head,*forw=head; left-=2; right--;
        while(right--){
            forw = forw->next;
        }
        if(left == -1){
            return reverse(head,forw,forw->next);
        }
        while(left--){
            if(prev->next!=NULL)
                prev = prev->next;
        }
        // cout<<prev->val<<" "<<forw->next<<endl;
        ListNode* start = prev, *end = forw->next;
        start->next = reverse(prev->next,forw, forw->next);
        return head;
        
    }
};