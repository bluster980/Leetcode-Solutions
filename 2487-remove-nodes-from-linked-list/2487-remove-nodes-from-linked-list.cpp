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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr=head;
        while(curr!=NULL){
            while(!st.empty() && st.top() < curr->val){
                st.pop();
            }
            st.push(curr->val);
            curr=curr->next;
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        ListNode *start = new ListNode(999), *temp=start;
        for(int i=v.size()-1; i>=0; i--){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return start->next;
    }
};