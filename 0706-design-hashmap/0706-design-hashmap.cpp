class MyHashMap {
    private:
    const int my_size=10000;
    vector<list<pair<int,int>>>hash;
public:
    MyHashMap() {
        hash.resize(my_size);
    }
    
    void put(int key, int value) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                Mypair.second=value;
                return;
            }
        }
        Mylist.push_back({key,value});
    }
    
    int get(int key) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                return Mypair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto&Mylist=hash[key%my_size];
        for(auto&Mypair:Mylist){
            if(Mypair.first==key){
                Mylist.remove(Mypair);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */