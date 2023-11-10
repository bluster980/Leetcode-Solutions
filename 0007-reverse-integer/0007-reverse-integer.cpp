class Solution {
public:
    long long reverse(long long x) {
        queue<int> q;
        int sign = 0;
        if(x<0) 
        {
            sign = 1; 
            x = x*-1;
        }
        while(x>0){
            q.push(x%10);
            x=x/10;
        }
        long long res = 0;
        while(!q.empty()){
            res = res*10 + q.front();
            q.pop();
        }
        if(sign){
            res = res*-1;
        }
        // cout<<res;
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
        
    }
};