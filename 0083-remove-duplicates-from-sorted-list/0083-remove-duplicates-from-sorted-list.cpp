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
    ListNode* deleteDuplicates(ListNode* head) {
       if(head==NULL || head->next == NULL) return head;
       ListNode* temp = head, *prev = temp; 
       set<int> st; st.insert(temp->val); temp=temp->next; 
        while(temp!=NULL){
            int bf = st.size();
            st.insert(temp->val);
            int af = st.size();
            // cout<<bf<<" "<<af<<endl;
            if(af == bf){
                if(temp->next == NULL){
                    prev->next = NULL;
                }
                else{
                    prev->next = temp->next;
                }
            }
            else{
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};