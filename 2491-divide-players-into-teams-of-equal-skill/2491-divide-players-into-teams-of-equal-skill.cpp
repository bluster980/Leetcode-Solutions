class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(),skill.end());
    int len=size(skill);
    long long tot_chemistry=0;
    int tot_skill=skill[0]+skill[len-1];
    for(int i=0;i<len/2;i++){
        if(skill[i]+skill[len-1-i]!=tot_skill){return -1;}
        tot_chemistry+=skill[i]*skill[len-1-i];
    }
    return tot_chemistry;
    }
};