class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v; int t=0; 
        // int range = arr[arr.size()-1]; 
        // cout<<"range : "<<range<<endl;
        for(int i=1; i<1e5; i++){
            if(t<arr.size() && i==arr[t]) 
                t++;
            else{
                v.push_back(i);
            }
            if(v.size() >= k) 
                break;
        }
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        return v[v.size()-1];
    }
};