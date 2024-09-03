class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string v="";
        long long h=0;
        for(int i=0; i<n; i++){
            int u=((int)s[i]-96);
            v=v+to_string(u);
        }
        long long m=0;
        for(int i=0; i<k; i++){
            for(int j=0; j<v.size(); j++){
                m+=((int)v[j]-(int)'0');
            }
            v=to_string(m);
            m=0;
        }
    return stoi(v);
    }
};