class Solution {
public:
    int helper(vector<string>& words, int curr, vector<char> letters, vector<int>& score){
        if(curr<0)return 0;
        unordered_map<char, int>curr_dict, curr_word, remaining;
        for(int i=0;i<letters.size();i++){
            curr_dict[letters[i]]++;
        }
        for(int i=0;i<words[curr].size();i++){
            curr_word[words[curr][i]]++;
        }		
        vector<char>lettersr;
        remaining=curr_dict;
        int flag=1;
        for(auto temp:curr_word){
            if(curr_dict[temp.first]<temp.second){
                flag=0;
                break;
            }
            remaining[temp.first]-=temp.second;
        }
        if(flag==0){
            return helper(words, curr-1, letters, score);
        }
        int curr_score=0;
        for(int i=0;i<words[curr].size();i++){
            curr_score+=score[words[curr][i]-'a'];
        }
        for(auto temp:remaining){
            for(int i=0;i<temp.second;i++)
                lettersr.emplace_back(temp.first);
        }
        int ans2=helper(words, curr-1, lettersr, score)+curr_score;        
        return max(helper(words, curr-1, letters, score), ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        return helper(words, words.size()-1, letters, score);        
    }
};