class LRUCache {
public:
    struct ListNode {
        ListNode* prev;
        ListNode* next;
        int key,val;
        ListNode(int _key, int _val){
            key = _key;
            val = _val;
        } 
    };
    
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    unordered_map<int,ListNode*> mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(ListNode* root){
        ListNode* dumy = head->next;
        root->next = dumy;
        head->next = root;
        dumy->prev = root;
        root->prev = head;
    }
    
    void deletenode(ListNode* root){
        ListNode* temp = root->prev;
        ListNode* dumy = root->next;
        temp->next = dumy;
        dumy->prev = temp;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            ListNode* temp = mp[key];
            int valu = temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key] = head->next;
            return valu;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            ListNode* tt = mp[key];
            mp.erase(key);
            deletenode(tt);
        }
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new ListNode(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */