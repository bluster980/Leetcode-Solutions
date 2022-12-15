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
    ListNode* ad = new ListNode();
    ListNode* ans = ad;
    ListNode* dy;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1,*temp2=l2;
        int sum = 0;
        if(l1==NULL) return l1;
        while(temp!=NULL && temp2!=NULL){
            sum += temp->val + temp2->val;
            // cout<<temp->val<<" "<<temp2->val<<" "<<sum<<endl;
            if(sum > 9){
                ad->val = sum%10;
                ad->next = new ListNode();
                dy = ad;
                ad = ad->next;
                sum/=10;
            }
            else{
                ad->val = sum;
                ad->next = new ListNode();
                sum = 0;
                dy = ad;
                ad = ad->next;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        while(temp!=NULL){
            sum += temp->val;
            if(sum > 9){
                ad->val = sum%10;
                ad->next = new ListNode();
                dy = ad;
                ad = ad->next;
                sum/=10;
            }
            else{
                ad->val = sum;
                ad->next = new ListNode();
                dy = ad;
                sum = 0;
                ad = ad->next;
            }
            temp=temp->next;
        }
        while(temp2!=NULL){
            sum += temp2->val;
            if(sum > 9){
                ad->val = sum%10;
                ad->next = new ListNode();
                dy = ad;
                ad = ad->next;
                sum/=10;
            }
            else{
                ad->val = sum;
                ad->next = new ListNode();
                sum = 0;
                dy = ad;
                ad = ad->next;
            }
            temp2=temp2->next;
        }
        // cout<<sum<<endl;
        if(sum) 
        {ad->val = sum;
            ad = NULL;}
        else{
            dy->next = NULL;
        }
        // ad->next = NULL;
        return ans;
    }
};