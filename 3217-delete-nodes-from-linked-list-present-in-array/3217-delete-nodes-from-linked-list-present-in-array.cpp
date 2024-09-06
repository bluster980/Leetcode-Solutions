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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* prev = NULL;
        ListNode* ans = NULL;
        ListNode* temp = head;
        set<int> st ;
        for(auto x:nums) st.insert(x);

        while(temp != NULL){
            while( temp != NULL && st.find(temp -> val) != st.end()){
                temp = temp -> next;
            }
            if(prev == NULL){
                prev = temp;
                ans = temp;
            }
            else{
                prev -> next = temp;
                prev = prev ->next;
            }
            temp = temp == NULL ? temp : temp -> next;
        }
        return ans;
    }
};