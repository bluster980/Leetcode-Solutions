class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26);
        int maxx = 0;
        for(int i=0; i<tasks.size(); i++){
            frequency[tasks[i]-'A']++;
            maxx = max(maxx,frequency[tasks[i]-'A']);
        }
        int ans = (maxx-1) * (n+1);
        for(int i=0; i<26; i++){
            if(frequency[i] == maxx){
                ans++;
            }
        }
        return max(ans,(int)tasks.size());
    }
};