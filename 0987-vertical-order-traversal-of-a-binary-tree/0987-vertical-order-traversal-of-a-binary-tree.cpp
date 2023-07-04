/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void tra(TreeNode* root, multimap<map<int,int>,int> &mp){
        queue<pair<int,TreeNode*>> q; int level = 0, x = 0;
        q.push({0,root}); q.push({0,NULL});
        while(!q.empty()){
            int x = q.front().first;
            TreeNode* temp = q.front().second; q.pop();
            if(temp == NULL){
                if(q.empty()) break;
                q.push({0,NULL}); level++;
            }
            else{
                map<int,int> go; go.clear(); go.insert({x,level});
                mp.insert({go,temp->val});

                if(temp->left) q.push({x-1,temp->left});
                if(temp->right) q.push({x+1,temp->right});
            }
            
        }
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return vector<vector<int>> {};
        multimap<map<int,int>,int> mp; 
        vector<vector<int>> ans;
        tra(root,mp); 

        vector<int> yui; int prev;
        vector<pair<map<int, int>, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(),vec.end()); int tt = 0,temm=1; 
        for (auto pair : vec) {
            for (auto element : pair.first) {
                if(tt && prev != element.first){
                    ans.push_back(yui); yui.clear(); prev = element.first;
                }
                yui.push_back(pair.second);
                if(temm--) {prev = element.first; tt++;}
            }
        }
        ans.push_back(yui);
        return ans;
    }
};