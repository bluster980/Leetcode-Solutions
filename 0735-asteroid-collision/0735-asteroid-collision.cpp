// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& aster) {
//         vector<int> ans; bool destroyed = true;
//         for(int i=0; i<aster.size(); i++){
//             while(ans.size() && (ans.back() > 0) && (aster[i] < 0) && destroyed){
//                 if(ans.back() >= -aster[i]){
//                     destroyed = false;
//                 }
//                 else if(ans.back() <= -aster[i]){
//                     ans.pop_back();
//                 }
//             }
//             if(destroyed){
//                 ans.push_back(aster[i]);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};