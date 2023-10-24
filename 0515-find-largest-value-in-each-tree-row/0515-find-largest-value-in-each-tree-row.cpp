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
    vector<int> levelOrder(TreeNode* root){
        vector<int> ans; if (!root) return ans;
        queue<TreeNode*> q; q.push(root); q.push(NULL);
        int maxx = INT_MIN;
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            if(top == NULL){
                ans.push_back(maxx);
                maxx = INT_MIN;
                if(q.empty()) break;
                q.push(NULL);
            }
            else{
                maxx = max(maxx,top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> temp = levelOrder(root);
        return temp;
    }
};