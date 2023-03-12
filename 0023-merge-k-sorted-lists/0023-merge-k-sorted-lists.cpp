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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq; int count = 0;
        if(lists.size() == 0) return NULL;
        for(auto ls : lists){
            if(ls == NULL) {count++; continue;}
            while(ls!=NULL){
                pq.push(ls->val);
                ls = ls->next;
            }
        }
        if(count == lists.size()) return NULL;
        ListNode* head = new ListNode(NULL); 
        ListNode* temp = head,*curr;
        while(!pq.empty()){
            curr = new ListNode(NULL);
            temp->val = pq.top(); pq.pop();
            if(!pq.empty())
                temp->next = curr; temp=temp->next;
        }
        // temp = NULL;
        return head;
    }
};