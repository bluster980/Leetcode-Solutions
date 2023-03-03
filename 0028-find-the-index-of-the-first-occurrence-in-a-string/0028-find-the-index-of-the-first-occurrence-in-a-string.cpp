class Solution {
public:
    int strStr(string h, string n) {
        string temp;
        for(int i=0; i<n.size(); i++){
            temp.push_back(h[i]);
        }
        int k = 0;
        for(int i=n.size(); i<h.size(); i++){
            if(temp == n) return k;
            temp.erase(temp.begin());
            temp.push_back(h[i]);
            k++;
        }
        if(temp!=n) return -1;
        return k;
    }
};