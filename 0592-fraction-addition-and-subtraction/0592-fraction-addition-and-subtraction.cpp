class Solution {
public:
    string fractionAddition(string& s) {
        string numi = "";
        string deno = "";
        int n = s.length();
        bool flag = false;
        int i = 0;
        for (i; i < n; ++i) { //taking first fraction out
            if (i > 0 && (s[i] == '+' || s[i] == '-')) {
                i++;
                break;
            }
            if (s[i] == '/') {
                flag = true;
                continue;
            }
            if (flag) {
                deno += s[i];
            } else {
                numi += s[i];
            }
        }
        stack<char> st;
        int j = i - 1;
        if(i != n) //handles single fraction case
            for (i; i <= n; ++i) {
                if (i == n || s[i] == '+' || s[i] == '-') {
                    string numiTemp = "";
                    string denoTemp = "";
                    bool flag = false;
                    while (!st.empty()) {
                        if (st.top() == '/') {
                            flag = true;
                        } else if (flag) {
                            numiTemp += st.top();
                        } else {
                            denoTemp += st.top();
                        }
                        st.pop();
                    }
                    reverse(numiTemp.begin(), numiTemp.end());
                    reverse(denoTemp.begin(), denoTemp.end());
                    int x = stoi(deno);
                    int y = stoi(denoTemp);
                    int lcmm = (x * y) / __gcd(x, y);
                    deno = to_string(lcmm);
                    int a = stoi(numi);
                    int b = stoi(numiTemp);
                    a = a * (lcmm / x);
                    b = b * (lcmm / y);
                    int ans = 0;
                    if (s[j] == '-') {
                        ans = a - b;
                    } else {
                        ans = a + b;
                    }
                    numi = to_string(ans);
                    j = i;
                } else {
                    st.push(s[i]);
                }
            }
        flag = false;
        if(numi[0] == '-'){
            flag = true;
        }
        int a = stoi(numi);
        int x = stoi(deno);
        int lcmm = __gcd(a, x);
        a /= lcmm;
        x /= lcmm;
        if(flag){
            if(a >= 0){
                a *= -1;
            }
            if(x < 0){
                x *= -1;
            }
        }
        numi = to_string(a);
        deno = to_string(x);
        return numi + '/' + deno;
    }
};