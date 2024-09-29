class AllOne {
private:
    map<string, int> mp;
    int mx = INT_MIN;
    int mn = INT_MAX;
    string mx_cnt_str;
    string mn_cnt_str;
public:
    AllOne() {}
    
    void inc(string key) {
        mp[key]++;
        if(mp[key] >= mx){
            mx = mp[key];
            mx_cnt_str = key;
        }
        if(mn >= mp[key]){
            mn = mp[key];
            mn_cnt_str = key;
        }
        else if(mn_cnt_str == key){
            int mini = INT_MAX;
            for(auto it: mp){
                if(it.second < mini){
                    mn = it.second;
                    mn_cnt_str = it.first;
                    mini = it.second;
                }
            }
        }
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key] == 0){
            mp.erase(key);
        }
        if(mp.empty()){
            mx = INT_MIN;
            mn = INT_MAX;
            mx_cnt_str = "";
            mn_cnt_str = "";
        }
        else{
            if(mx_cnt_str == key){
                int maxi = INT_MIN;
                for(auto it: mp){
                    if(it.second > maxi){
                        mx = it.second;
                        mx_cnt_str = it.first;
                        maxi = it.second;
                    }
                }
            }
            if(mn_cnt_str == key){
                int mini = INT_MAX;
                for(auto it: mp){
                if(it.second < mini){
                    mn = it.second;
                    mn_cnt_str = it.first;
                    mini = it.second;
                    }
                }
            }
        }
    }
    
    string getMaxKey() {
        return mx_cnt_str;
    }
    
    string getMinKey() {
        return mn_cnt_str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */