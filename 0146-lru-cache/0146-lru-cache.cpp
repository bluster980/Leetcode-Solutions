#define ff first
#define ss second
class LRUCache {
public:
    map<int,int>kp,m; int count = 0;
    //key, counter in queue
    queue<pair<int,int>> q;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        if(m[key]==0)
            return -1;
        
        q.push({key,++m[key]});
        return kp[key];
    
    }
    
    void put(int key, int value) {
        kp[key] = value;
        
        if(m[key]>0)
        {
            q.push({key,++m[key]});
            return ;
        }
        
        if(count<capacity)
        {
            if(m[key]==0 || m.count(key)==0)
                count++;
            q.push({key,++m[key]});
            return ;
        }
            
        while(1)
        {
            pair<int,int> tem = q.front();
            q.pop();
            if(m[tem.ff]==tem.ss)
            {
                m[tem.ff] = 0;
                q.push({key,++m[key]});
                return ;
            }
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */