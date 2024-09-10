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
private:
int gcd(int val1, int val2){
    if (val1 == 0){
        return val2;
    }
    if (val2 ==0){
        return val1;
    }
    val2 = val2 % val1;
   return gcd(val2,val1);
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head==NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* curr = head->next;

        while(temp!=NULL && curr!=NULL){
            int val1 = temp->val;
            int val2 = curr->val;

            if (val1>=val2){
                swap(val1,val2);
            }
            int gcdval = gcd(val1,val2);

            ListNode* mid = new ListNode(gcdval);
            temp->next = mid;
            mid->next = curr;

           if (curr!=NULL) temp = curr;
           if (temp!=NULL) curr = curr->next;
        }

        return head;
    }
};