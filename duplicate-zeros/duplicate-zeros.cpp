class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = 0; bool flag = false;
        for(int i=0; cnt+i<arr.size(); i++){
            if(arr[i]==0){
                cnt++;
            }
            if(cnt+1+i > arr.size()) {
                cnt--; flag = true;
            }
        }
        cout<<cnt<<endl;
        cout<<flag<<endl;
        
        if(cnt != arr.size() && cnt!=0){
            int j = arr.size()-cnt-1; int x = arr.size()-1;
            if(flag){
                arr[x] = 0;
                x--; j--;
            }
            for(int i=j; i>=0; i--){
                if(i<arr.size() && arr[i] == 0){
                    arr[x] = 0; x--;
                }
                arr[x] = arr[i]; x--;
            }
        }
    }
};