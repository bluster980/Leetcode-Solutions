class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                ans.push_back(0);
                if(arr.size() == ans.size()) break;
            }
            ans.push_back(arr[i]);
            if(arr.size() == ans.size()) break;
        }
        arr = ans;
    }
};