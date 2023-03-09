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
        if(head == NULL) return head;
        set<ListNode*> st;
        while(head != NULL){
            int bf = st.size();
            st.insert(head);
            int af = st.size();
            if(af == bf) return head;
            head = head->next;
        }
        return NULL;
    }
};