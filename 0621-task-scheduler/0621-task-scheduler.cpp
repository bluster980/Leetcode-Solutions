class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26); int maxx = 0;
        for(int i=0; i<tasks.size(); i++){
            v[tasks[i]-'A']++;
            maxx = max(maxx,v[tasks[i]-'A']);
        }
        int ans = (maxx-1) * (n+1);
        for(int i=0; i<26; i++){
            if(v[i] == maxx) ans++;
        }
        return max(ans, (int)tasks.size());
    }
};