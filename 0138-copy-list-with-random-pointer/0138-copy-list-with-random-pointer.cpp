/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp){
            Node* forw = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = forw;
            temp=forw;   
        }
        
        Node* curr =head;
        while(curr!=NULL){
            if(curr->random!=NULL)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        
        Node* ans=new Node(0);
        Node* helper=ans;
    
        while(head){
            helper->next=head->next;
            helper=helper->next;
            
            head->next=head->next->next;
            head=head->next;
        }
        return ans->next;
    }
};