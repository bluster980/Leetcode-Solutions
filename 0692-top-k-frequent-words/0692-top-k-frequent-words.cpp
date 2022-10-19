class Solution {
public:
    struct Comp {
      bool operator()(const std::pair<int,string> &a, const std::pair<int,string> &b) {
        if (a.first != b.first) {
          return a.first > b.first;
        }
        return a.second < b.second;
      }

    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp; vector<pair<int,string>> v;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        for(auto xx:mp){
            v.push_back({xx.second,xx.first});
        }
        Comp comp_functor;
        sort(v.begin(),v.end(),comp_functor);
        vector<string> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
            // cout<<v[i].second<<" "<<v[i].first<<endl;
        }
        return ans;
    }
};