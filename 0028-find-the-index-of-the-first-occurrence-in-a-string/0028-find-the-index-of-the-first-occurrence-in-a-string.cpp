class Solution {
public:
    int strStr(string h, string n) {
        int i=0,j=n.size()-1;
        while(i<h.size()){
        	// cout<<h.substr(i,j+1)<<endl;
            if(h.substr(i,j+1) == n){
                return i;
            }
            i++; 
        }
        return -1;
    }
};