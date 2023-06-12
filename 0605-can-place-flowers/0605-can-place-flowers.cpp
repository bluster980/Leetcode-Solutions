class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans = 0;
        bool last = (f[f.size()-1] == 1)?false:true;
        bool first = (f[0] == 1)?false:true;
        for(int i=0; i<f.size(); i++){
            int count = 0;
            while(i<f.size() && f[i]==0){
                count++; i++;
            }
            if(first) {count++; first = false;}
            if(i>=(f.size()-1) && last) {count++; last = false;}
            ans += max(0,(int)ceil((count-2)/2.0)); 
        }
        // cout<<ans<<endl;
        return ans>=n;
    }
};