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
    vector<int> v;
    void iot(TreeNode* root, long long sum){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            sum = sum*10 + root->val;
            v.push_back(sum);
        }
        sum = sum*10 + root->val;
        if(root->left != NULL){
            iot(root->left,sum);
        }
        if(root->right != NULL)
        {
            iot(root->right,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        iot(root,0);
        long long ans = 0;
        for(int i=0; i<v.size(); i++){
            ans += v[i];
        }
        return ans;
    }
};