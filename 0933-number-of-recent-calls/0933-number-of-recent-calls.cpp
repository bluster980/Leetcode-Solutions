class RecentCounter {
public:
unordered_map<int,int>m;
int i=0;
RecentCounter() {
        
    }
    
    int ping(int t) {
        int x=-3000;
        int y=0;
         x=x+t;
         y=y+t;
        m[i]=t;
        i++;
        int z=0;
        for(auto it:m)
        {
            if(it.second<=y && it.second>=x)
            {
                z++;
            }
        }
        return z;
    }

};