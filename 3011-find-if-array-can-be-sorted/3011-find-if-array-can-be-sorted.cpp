class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int f=0;
        int scount=0;
        int s1=-1;
        int max1=INT_MIN;
        int min1=INT_MAX;
        int p=nums[0];
        int indicator=0;
        int k;
        if(nums.size()==1){
            return true;
        }
        else {
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]<=nums[i+1]){
                    f=1;
                }else{
                    f=0;
                    break;
                }
            }
        }

        if(f==1){
            return true;
        }
        else{
            for(int i=0;i<nums.size();i++){
                scount=0;
                 k=nums[i];
                 int l=k;
                while(l>0){
                    if(l&1==1){
                        scount++;
                    }
                    l=l>>1;
                }
                if(scount==s1){
                    if(k>=p){
                    max1=max(max1,k);
                    }
                    else{
                        indicator=1;
                        break;
                    }
                    
                }else{
                    s1=scount;
                    if(k>=max1){
                        
                        p=max1;
                        max1=k;
                    }
                    else{
                        indicator=1;
                        break;
                    }

                }
            }
        }
        cout<<p;
        if(indicator==1){
            return false;
        }else{
            return true;
        }
    }
};