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
    bool hasCycle(ListNode *head) {
        set<ListNode *> st;
        int bf,af;
        while(head!=NULL && head->next!=NULL && bf!=af){
            bf = st.size();
            st.insert(head);
            af = st.size();
            head=head->next;
        }
        return (head==NULL || head->next==NULL)?false:true;
    }
};