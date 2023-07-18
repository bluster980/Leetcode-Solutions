class Node{
    public:
    int val;
    Node *nxt,*prv;
    Node():val(-1),prv(nullptr),nxt(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {
        head->nxt = tail;
        tail->prv = head;
    }
    
    int get(int key) {
        if(Arr[key].val == -1) return -1;
        else{
            to_tail(&Arr[key]);
            return Arr[key].val;
        }
    }
    
    void put(int key, int value) {
        if(Arr[key].val != -1){
            to_tail(&Arr[key]);
            Arr[key].val = value;
            return;
        }
        else{
            if(len+1<=capacity){   
                insert(&Arr[key]);
               len++;
                Arr[key].val = value;
            }
            else{
            
                head->nxt->val = -1;
                remove(head->nxt);

                Arr[key].val = value;
                insert(&Arr[key]);
            }
        }
    }

    void to_tail(Node* cur){
        remove(cur);
        insert(cur);
    }

    void remove(Node* cur){
        cur->nxt->prv = cur->prv;
        cur->prv->nxt = cur->nxt;
    }

    void insert(Node* cur){
        tail->prv->nxt = cur;
        cur->prv = tail->prv;

        cur->nxt = tail;
        tail->prv = cur;
    }

    array<Node,10005> Arr;
    int len = 0,capacity;
    Node* head = new Node,*tail = new Node;
};