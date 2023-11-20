class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int gla=0,pap=0,met=0; int lasg=0,lasm=0,lasp=0;
        for(int i=1; i<travel.size(); i++){
            travel[i] = travel[i]+travel[i-1];
        }
        int countg=0,countp=0,countm=0;
        for(int i=0; i<garbage.size(); i++){
            string s = garbage[i];
            for(int j=0; j<s.size(); j++){
                if(s[j]=='G'){
                    lasg=i;
                    countg++;
                }
                else if(s[j]=='M'){
                    lasm=i;
                    countm++;
                }
                else if(s[j]=='P'){
                    lasp=i;
                    countp++;
                }
            }
        }
        if(lasg!=0 && countg!=0){
            gla = travel[lasg-1] + countg;
        }
        else{
            gla = countg;
        }
        if(lasp!=0 && countp!=0){
            pap = travel[lasp-1] + countp;
        }
        else{
            pap = countp;
        }
        if(lasm!=0 && countm!=0){
            met = travel[lasm-1] + countm; 
        }
        else{
            met = countm;
        }
        // cout<<lasg<<" "<<lasp<<" "<<lasm<<endl;
        // cout<<gla<<" "<<pap<<" "<<met<<endl<<endl;
        return gla+pap+met;
    }
};