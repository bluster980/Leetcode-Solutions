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
    int pairSum(ListNode* head) {
        ListNode* temp = head,*twice=head; int cnt = 0;
        while(temp!=NULL) {temp=temp->next; cnt++;}
        vector<int> v(cnt/2,0);
        int i=0;
        while(i<v.size() && twice!=NULL){
            v[i]+=twice->val;
            // cout<<twice->val<<" ";
            twice=twice->next;
            i++;
        } i--;
        cout<<endl;
        while(i>=0 && twice!=NULL){
            v[i]+=twice->val;
            // cout<<twice->val<<" ";
            twice=twice->next;
            i--;
        }
        // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        return *max_element(v.begin(),v.end());
        
    }
};