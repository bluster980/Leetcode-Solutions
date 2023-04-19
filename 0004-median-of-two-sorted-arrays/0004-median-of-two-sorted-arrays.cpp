class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {       
        vector<int> a;
        int i = 0;
        int j = 0;
        double result;
        if(nums1.size()==0 && nums2.size()!=1){
            int p = 0;
            while(p<=nums2.size()-1){
                a.push_back(nums2[p]);
                p++;
            }
            
        }
        else if(nums2.size()==0 && nums1.size()!=1){
            
            int p = 0;
            while(p<=nums1.size()-1){
                a.push_back(nums1[p]);
                p++;
            }
            
            
        }
        else if(nums1.size()==0 && nums2.size()==1){
            
            result = nums2[0]/1.00000;
            return result;
            
            
        }
        else if(nums2.size()==0 && nums1.size()==1){
            
            result = nums1[0]/1.00000;
            return result;
            
        }
        else if(nums1.size()==0 && nums2.size()==0){
            return -1;
        }
        else{
            
                while(i<=nums1.size()-1 && j<=nums2.size()-1){
                if(nums1[i]<nums2[j]){
                    a.push_back(nums1[i]);
                    i++;
                }
                else if(nums1[i]>nums2[j]){
                    
                    a.push_back(nums2[j]);
                    j++;
                }
                else if(nums1[i]==nums2[j]){
                    a.push_back(nums1[i]);
                    a.push_back(nums2[j]);
                    i++;
                    j++;
                }
            }
            if(i>nums1.size()-1){
                while(j<=nums2.size()-1){
                    a.push_back(nums2[j]);
                    j++;
                }
            }
            else if(j>nums2.size()-1){
                while(i<=nums1.size()-1){
                    a.push_back(nums1[i]);
                    i++;
                }
            }
            
        }                
        if(a.size()%2==0){
            long x = a.size()/2;
            long y = x - 1;
            result = (a[x]+a[y])/2.00000;
        }
        else{
            long z = a.size()/2;
            result = a[z]*1.00000;
        }
    return result;       
    }
};