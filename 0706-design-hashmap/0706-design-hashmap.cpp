class MyHashMap {
public:
    vector<pair<int,int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0; i<v.size(); i++){
            if(v[i].first == key){
                v.erase(v.begin()+i);
                v.push_back({key,value});
                return;
            }
        }
        v.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0; i<v.size(); i++){
            if(v[i].first == key){
                return v[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int x,y; int i=0;
        while(i<v.size()){
            if(v[i].first == key){
                v.erase(v.begin()+i);
                return;
            }
            i++;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */