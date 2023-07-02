class Solution {
public:
    vector<int> v;
    int maxProduct(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            int temp = 0;
            for(int j=0; j<words[i].size(); j++){
                temp |= (1 << (words[i][j]-'a'));
                // cout<<1<<(words[i][j]-'a');
            }
            v.push_back(temp);
        // cout<<endl;
        }
        int maxx = 0;
        for(int i=0; i<v.size(); i++){
            for(int j=i; j<v.size(); j++){
                if(!(v[i]&v[j])){
                    int te = words[i].size()*words[j].size();
                    maxx = max(maxx,te);
                }
            }
        }
        return maxx;
    }
};