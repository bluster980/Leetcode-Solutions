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
    vector<long long> v;
    int levels = 0;
    void traverse(TreeNode* root)
    {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long nodeCount = q.size();
            long long temp = 0;
            while (nodeCount > 0) {
                TreeNode* node = q.front();
                temp += node->val;
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                nodeCount--;
            }
            levels++;
            v.push_back(temp);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        traverse(root);
        sort(v.rbegin(),v.rend());
        if(levels < k) return -1;
        return v[k-1];
    }
};