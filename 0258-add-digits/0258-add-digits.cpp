class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        int a = 0;
        while(s.size()!=1){
            for (int i = 0; i < s.size(); ++i)
            {
                a = a + (s[i]-'0');
            }
            s = to_string(a);
            a = 0;
        }
        return s[0]-'0';
        // cout<<s[0]-'0'<<endl;
    }
};